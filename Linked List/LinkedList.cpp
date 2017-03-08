#include <iostream>

// Issue: Rootnode is holding an empty element.
// TODO: Clean this stuff up
// TODO: Remove conditions for rootNode

template <typename Element>
struct LinkedListNode {
    LinkedListNode* nextNode = nullptr;
    Element element;
};

template <typename Element>
class LinkedList
{
public:
    LinkedList(){}
    ~LinkedList()
    {
        //TODO: Delete everything.
    }

    void push_back(Element element)
    {
        if (rootNode == nullptr)
        {
            rootNode = new LinkedListNode<Element>;
            rootNode->element = element;
            return;
        }

        // Start at the root
        LinkedListNode<Element>* node = rootNode;

        // Traverse the list
        while (node->nextNode != nullptr)
            node = node->nextNode;

        // Add next element
        node->nextNode = new LinkedListNode<Element>;
        node->nextNode->element = element;
    }

    int count()
    {
        // Declare accumulator
        int acc = 0;

        // Start at the root
        LinkedListNode<Element>* node = rootNode;

        // Traverse the list
        while (node->nextNode != nullptr)
        {
            node = node->nextNode;
            ++acc;
        }

        // Add one since the index starts at 0
        return ++acc;
    }

    Element at(int index)
    {
        // Declare accumulator
        int acc = 0;

        // Start at the root
        LinkedListNode<Element>* node = rootNode;

        // Traverse the list
        while (node != nullptr)
        {
            // Checks if this is the index
            if (acc == index)
                return node->element;

            node = node->nextNode;
            acc++;
        }

        // If it reaches here return nothing/exception/message that there it's not on the list.
        // TODO: Handle this case
    }

    //TODO
    /*Element back()
    {
        return;
    }*/

private:
    LinkedListNode<Element>* rootNode = nullptr;
};

int main()
{
    LinkedList<int> intList;

    intList.push_back(10);
    intList.push_back(3);
    intList.push_back(11);
    intList.push_back(11);
    intList.push_back(12);

    intList.push_back(14);
    intList.push_back(13);
    intList.push_back(17);
    intList.push_back(9);
    intList.push_back(33);

    std::cout << "IntList count: " << intList.count() << std::endl;
    for (int i = 0; i < intList.count(); i++)
        std::cout << "IntList at " << i << ": " << intList.at(i) << std::endl;

    return 0;
}
