// collatz conjecture "back to 1"
#include <cs50.h>
#include <stdio.h>
int collatz(int n);

int main(void) 
{
    int n = 1;
    do {
        n = get_int("Enter a number \n");
    }
    while (n <= 0);
    printf("number of steps is %i\n", collatz(n));
}

int collatz(int n)
{
    int count = 0;
    
    if (n == 1)
    {
        return count;
    } 
    else {
       while (n != 1)
       {
            if (n % 2 == 0) // if even
            {
                count++;
                n = n/2;
            }
            else if (n % 2 != 0) // if odd
            {
                count++;
                n = 3 * n + 1;
            }
       }
       return count; 
    }
}
