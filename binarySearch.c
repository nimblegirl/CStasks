#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // An array of numbers
    int numbers[] = {4, 8, 15, 16, 23, 42, 50, 77};
    int size = sizeof(numbers)/ sizeof(numbers[0]);
    int left = 0;
    int right = size -1;

    // Search for 50
    while ( left <= right)
    {
        int middle  = left + (right - left)/2; 
            
        if (numbers[middle] == 50)
        {
            printf("Found in %i bucket\n", middle);
            return 0;
        }
        if (numbers[middle] < 50)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - left;
        }
    }
    printf("Not found\n");
    return 1;
}
