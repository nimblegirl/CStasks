#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // An array of numbers
    int numbers[] = {4, 8, 15, 16, 23, 42};
    int size = sizeof(numbers)/ sizeof(numbers[0]);

    // Search for 50
    for (int i = 0; i < size-1; i++)
    {
        printf("%i\n", numbers[i]);
        if (numbers[i] == 50)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
