#include <stdio.h>

int main(void)
{
    int a = 5, b = 25;

    // Print original
    printf("a: %d\nb: %d\n\n", a, b);

    // XOR
    a ^= b;
    b ^= a;
    a ^= b;

    // Print switched
    printf("a: %d\nb: %d\n\n", a, b);

    return 0;
}
