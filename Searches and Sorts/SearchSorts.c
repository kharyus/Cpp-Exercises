#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Forward Declarations
bool linearSearch(int value, int values[], int n);
bool binarySearch(int value, int values[], int n);
void selectionSort(int values[], int n);
void bubbleSort(int values[], int n);
void insertionSort(int values[], int n); // TODO

void main(void)
{
    // Vars
    int value = 0;
    int values[] = {9,1,8,2,7,3,6,4,5};

    // Input
    scanf("%d", &value);

    // Sort
    //selectionSort(values, 9);
    bubbleSort(values, 9);
    //insertionSort(values, 9);

    // Search
    if (binarySearch(value, values, 9))
    {
        printf("\nFound value\n");
    }
    else
    {
        printf("\nDidn't find value\n");
    }

    return 0;
}

/**
 * Returns true if value is in array of n values, else false.
 */
bool linearSearch(int value, int values[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (value == values[i])
        {
            return true;
        }
    }
    return false;
}

/**
 * Returns true if value is in array of n values, else false.
 *
 * Array must be sorted as a requirement.
 */
bool binarySearch(int value, int values[], int n)
{
    float currentIndex = n/2.;
    printf("log: %f - ilog: %d\n", log2(n), (int) ceil(log2(n)));

    // Loop log2(n) times rounded up.
    for (int i = 2, maxIt = ceil(log2(n)); i < maxIt+2; i++)
    {
        // DEBUG
        printf("%f - %d\t", currentIndex, values[(int) currentIndex]);
        // Check current position.
        if (value == values[(int) currentIndex])
        {
            return true;
        }
        // Check if intended value is greater than the current position.
        else if (value > values[(int) currentIndex])
        {
            currentIndex += n / exp2(i);
        }
        // Check if intended value is less than the current position.
        else if (value < values[(int) currentIndex])
        {
            currentIndex -= n / exp2(i);
        }
    }

    // Value not found
    return false;
}

/**
 * Sorts array of n values.
 */
void selectionSort(int values[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // Reinitialize lowest every iteration.
        int lowest = i;

        // Verify each of the remaining numbers for
        for (int j = i+1; j < n; j++)
        {
            if (values[j] < values[lowest])
            {
                lowest = j;
            }
        }

        // Swap current i with lowest
        swap(&values[i], &values[lowest]);
    }
}

/**
 * Sorts array of n values.
 */
void bubbleSort(int values[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (values[i] < values[j])
            {
                swap(&values[i], &values[j]);
            }
        }
    }
}

/**
 * Sorts array of n values.
 */
void insertionSort(int values[], int n)
{
    // TODO
}


/**
 * Swaps two values.
 */
void swap(int* value1, int* value2)
{
    // Check if value1 and 2 are different variables, otherwise it will cancel itself.
    // Here i just check if they have different values, but the logic is the same.
    if (*value1 != *value2)
    {
        *value1 ^= *value2;
        printf("%d\n", *value1);
        *value2 ^= *value1;
        printf("%d\n", *value2);
        *value1 ^= *value2;
        printf("%d\n\n", *value1);
    }
}
