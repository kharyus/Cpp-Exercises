#include "Server.h"

#include <iostream>
#include <sstream>

namespace sv
{
    Server::Server()
    {
        // Sets listeners as non-blocking.
        listener.setBlocking(false);

        // Opens thread to listen.
        startListening();

        // Initializes random seed.
        srand(time(NULL));

        // Initializes first position to be filled later.
        // The clients vectors must always have one free position for someone to fill.
        // Reason: sf::TcpSocket not copyable/movable.
        clients.emplace_back();
    }

    Server::~Server()
    {
        // Join all threads
        listenerThread.join();
        for (client : clients) // For some reason using this type of for, i don't need to worry about the empty thread on top of the stack.
        {
            client.thread.join();
        }
    }

    void Server::listenerThreadFunc()
    {
        while (running && listening)
        {
            if (listener.accept(clients.back().socket) == sf::Socket::Done)
            {
                // Connection accepted.
                std::cout << "Connection successful to " << clients.back().socket.getRemoteAddress() << "!\n";

                // Set client's id.
                clients.back().id = clients.size();

                // Create temporary thread and swap it with the current client's thread.
                std::thread tempThread(clientThreadFunc, this, &clients.back());
                std::swap(tempThread, clients.back().thread);

                // Create the empty position to be filled by the next client.
                clients.emplace_back();
            }
        }
    }

    void Server::startListening()
    {
        // Bind the listener to a port
        if (listener.listen(53000) == sf::Socket::Done)
        {
            std::cout << "Server listening!" << "\n";
        }

        // Create temporary thread and swap it with this instance's thread.
        std::thread tempThread(listenerThreadFunc, this);
        std::swap(tempThread, listenerThread);
    }

    void Server::clientThreadFunc(Client* client)
    {
        std::string s;
        sf::Packet packet;
        bool threadRunning = true;
        while (threadRunning)
        {
            if (client->socket.receive(packet) != sf::Socket::Disconnected)
            {
                std::stringstream ss;
                ss << 'P' << client->id;
                packet >> s;
                std::cout << ss.str() << ' ' << s << '\n';
                if (s == "START")
                {
                    packet.clear();
                    ss << " asked to Start";
                    sendToEveryOtherClient(ss.str(), client->id);
                    packet << "Start received";
                    client->socket.send(packet);
                }
                else if (s == "TAKE")
                {
                    packet.clear();
                    std::string card = drawCard();
                    ss << " got " << card;
                    sendToEveryOtherClient(ss.str(), client->id);
                    packet << card;
                    client->socket.send(packet);
                }
                else if (s == "PASS")
                {
                    packet.clear();
                    ss << " passed";
                    sendToEveryOtherClient(ss.str(), client->id);
                    packet << "Passed";
                    client->socket.send(packet);
                }
                else if (s == "QUIT")
                {
                    ss << " disconnected";
                    sendToEveryOtherClient(ss.str(), client->id);
                    std::cout << "Client with IP: " << client->socket.getRemoteAddress() << " and ID: " << client->id << " Disconnected" << '\n';
                    client->socket.disconnect();
                    threadRunning = false;
                }
                packet.clear();
            }
            else
            {
                std::cout << "Client with IP: " << client->socket.getRemoteAddress() << " and ID: " << client->id << " Disconnected" << '\n';
                client->socket.disconnect();
                threadRunning = false;
            }
        }
        // Thread stopped running, clean it.
        // TODO - SOON TM
    }

    const std::string Server::drawCard()
    {
        std::stringstream ss;
        short i = rand() % 13;

        // Number
        i = (rand() % 13)+1;
        ss << (i == 1) ? "Ace"
            : (i == 11) ? "Jack"
            : (i == 12) ? "Queen"
            : (i == 13) ? "King"
            : i;

        // Types
        i = rand() % 4;
        ss << (i == 0) ? " Club"
            : (i == 1) ? " Diamond"
            : (i == 2) ? " Heart"
            : " Spade";

        return ss.str();
    }

    void Server::sendToEveryOtherClient(const std::string& message, const unsigned long id)
    {
        sf::Packet packet;
        packet << message;
        for (client : clients)
            if (client.id != id)
            {
                client.socket.send(packet);
            }
    }
}
