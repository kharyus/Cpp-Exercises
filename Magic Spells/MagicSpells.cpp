// Hackerrank challenge.
// TODO: Finish this thing by implementing the Longest Common Subsequence
    if (dynamic_cast<Fireball*>(spell))
        dynamic_cast<Fireball*>(spell)->revealFirepower();
    else if (dynamic_cast<Frostbite*>(spell))
        dynamic_cast<Frostbite*>(spell)->revealFrostpower();
    else if (dynamic_cast<Waterbolt*>(spell))
        dynamic_cast<Waterbolt*>(spell)->revealWaterpower();
    else if (dynamic_cast<Thunderstorm*>(spell))
        dynamic_cast<Thunderstorm*>(spell)->revealThunderpower();
    else
    {
        // Need to implement Longest Character Sequence
        std::string scrollUsed = spell->revealScrollName();
        std::string journalSpell = SpellJournal::journal;
        std::string combined = std::string();
        int nfound = 0;
        int lastFound = 0;
        for (int j = 0; j < journalSpell.length(); ++j)
        {
            for (int i = lastFound; i < scrollUsed.length(); ++i)
            {
                if (scrollUsed[i] == journalSpell[j])
                {
                    combined += scrollUsed[i];
                    ++nfound;
                    lastFound = i;
                    break;
                }
            }
        }
        
        std::cout << nfound << std::endl;
    }
