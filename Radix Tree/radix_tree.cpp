/**
 *  Currently only strings
 */

#include <iostream>
#include <vector>

// TODO: Clean all the mess and implement Template

struct RadixTreeNode {
    std::vector<RadixTreeNode> nextNodes;
    char element;
};

// Root element
class RadixTree {
public:
    RadixTree(){}

    /**
     *  Inserts list of elements into radixtree
     */
    void insert(std::string elementList, RadixTreeNode* node = nullptr /*TODO*/, int index = 0)
    {
        // Edge guard
        if (index < elementList.length())
        {
            for (int i = 0; i < node->nextNodes.size(); i++)
            {
                if (elementList[index] == node->nextNodes[i].element)
                {
                    // Found the element, go to next.
                    insert(elementList, &node->nextNodes[i], ++index);

                    // Don't need to insert node.
                    return;
                }
            }

            // The element is not present in the list, insert node
            // and all the next elements (they wouldn't need verification, so can optimize that)
            node->nextNodes.emplace_back();
            node->nextNodes.back().element = elementList[index];

            // Debug
            std::cout << "Index: " << index << "\tElementList Length: " << elementList.length() << "\tElement: " << node->nextNodes.back().element << std::endl;

            insert(elementList, &node->nextNodes.back(), ++index);
        }
    }

    /**
     *  Counts number of elements in tree.
     */
    int countNodes(RadixTreeNode* node = nullptr)
    {
        int acc = 0;
        for (int i = 0; i < node->nextNodes.size(); i++)
        {
            acc += countNodes(&node->nextNodes[i]) + 1;
        }
        return acc;
    }

//private:
    RadixTreeNode rootNode;
};

int main()
{
    RadixTree tree;

    tree.insert("banana",&tree.rootNode);
    tree.insert("banono",&tree.rootNode);
    tree.insert("banone",&tree.rootNode);
    tree.insert("banonil",&tree.rootNode);

    std::cout << "Node Count: " << tree.countNodes(&tree.rootNode) << std::endl;
    std::cout << "Root Node Size: " << tree.rootNode.nextNodes.size() << std::endl;

    return 0;
}
