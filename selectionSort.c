// sort by selecting smallest element
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int array[] = {7, 5, 8, 16, 2};
    int size = sizeof(array)/ sizeof(array[0]);
    
    for (int i = 0; i < size - 1; i++)
    {
        int min_i = i;
        
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min_i])
            {
                min_i = j;
            }
        }
        
        int temp = array[min_i];
        array[min_i] = array[i];
        array[i] = temp;
    }
    
    printf("sorted array \n");
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
    return 0;
}
