#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int> uniq(new int(1));

    std::cout << *uniq << std::endl;

    std::unique_ptr<int>* uniq2uniq = &uniq;

    // Multiple pointers pointing to the same place indirectly.
    // The first unique pointer still manages the memory and is responsible for the deletion of the obj.
    // But the second is there just to avoid making expensive copies.
    std::cout << *uniq << " " << **uniq2uniq << std::endl;

    return 0;
}
