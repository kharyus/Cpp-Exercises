#include <iostream>

int main()
{
	
	unsigned int i = 0;
	
	i |= 1 << 1;

	std::cout << "Size of Byte: " << sizeof(i);
	std::cout << "Byte Value: " << i;
	
	return 0;
}
