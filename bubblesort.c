// sorts form smallest to largest
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int array[] = {7, 5, 8, 16, 2};
    int size = sizeof(array)/ sizeof(array[0]);
    int counter = -1;
    
    while (counter != 0)
    {
        counter = 0;
        for (int i = 0; i < size - 1; i++)
        {
            int next = array[i + 1];
            if (array[i] > next)
            {
                array[i + 1] = array[i];
                array[i] = next;
                counter++;
            }
        }
    }
    
    printf("sorted array \n");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
    return 0; 
}
