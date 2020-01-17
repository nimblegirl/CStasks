#include <cs50.h>
#include <stdio.h>
int divide(int left, int right, int array[], int size);
int merge(int left, int middle, int right, int array[], int size);

int main(void)
{
    int num[] = {7, 5, 8, 16, 2};
    int size = sizeof(num)/sizeof(num[0]);
    int left = 0; // fist el index
    int right = size - 1; // last el index
    
    divide(left, right, num, size);
    
    printf("Sorted array \n");
    for (int i = 0; i < size; i++)
    {
        printf(" %d", num[i]);
    }
    printf("\n");
    return 0;
}

int divide(int left, int right, int array[], int size)
{
    if (left < right)
    {
        int middle = left + (right - left)/2;
        
        divide(left, middle, array, size);
        
        divide(middle + 1, right, array, size);
        
        merge(left, middle, right, array, size);
    }
    return 1;
}

int merge(int left, int middle, int right, int array[], int size)
{
    int array_helper[size];
    for (int i = left; i < size; i++)
    {
        array_helper[i] = array[i];
    }
    
    int i = left;
    int mid = middle + 1;
    int j = left;
    
    while (i <= middle && mid <= right)
    {
        if (array_helper[i] <= array_helper[mid])
        {
            array[j] = array_helper[i];          
            i++;
        }
        else
        {
            array[j] = array_helper[mid];
            mid++;
        }
        j++;
    }
    while (i <= middle)
    {
        array[j] = array_helper[i];
        j++;
        i++;
    }
    return 2;
}



