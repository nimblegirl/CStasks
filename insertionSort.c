// sort by inserting element into sorted array 
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int num[] = {7, 5, 8, 16, 2};
    int size = sizeof(num)/sizeof(num[0]);
    
    for( int i = 1; i < size; i++)
    {
        int curr = num[i];
        int j = i - 1;
        
        while(j >= 0 && num[j] > curr)
        {
            num[j + 1] = num[j];
            j = j - 1;
        }
        
        num[j + 1] = curr;
    }
    
    printf("sorted array \n");
    for (int i = 0; i < size; i++)
        printf("%d ", num[i]);
    printf("\n");
    return 0;
}
