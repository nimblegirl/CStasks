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
    // check if left is smaller than right, if no - array is sorted
    if (left < right)
    {
        int middle = left + (right - left)/2; // index of the middle element
        
        divide(left, middle, array, size); // proceed with the left side of the array
        
        divide(middle + 1, right, array, size); // proceed with the right side of the array
        
        merge(left, middle, right, array, size); // combine two sorted arrays into 1
    }
    return 1;
}

int merge(int left, int middle, int right, int array[], int size)
{
    int array_helper[size]; // new helper array
    for (int i = left; i < size; i++)
    {
        array_helper[i] = array[i]; // copy all old array
    }
    
    int i = left;
    int mid = middle + 1;
    int j = left;
    // copy the smallest element either from the left or from the right side of the helper array into a target array[j]
    while (i <= middle && mid <= right)
    {
        // if the smallest is from the left
        if (array_helper[i] <= array_helper[mid])
        {
            array[j] = array_helper[i];          
            i++;
        }
        // if the smallest is form the right
        else
        {
            array[j] = array_helper[mid];
            mid++;
        }
        j++;
    }
    
    // copy the rest of the left side of the helper array into target array
    while (i <= middle)
    {
        array[j] = array_helper[i];
        j++;
        i++;
    }
    return 2;
}
