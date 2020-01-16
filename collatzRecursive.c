// collatz conjecture "back to 1" recursive
#include <cs50.h>
#include <stdio.h>
int collatz(int n);

int main(void) 
{
    int n = get_int("Enter a number \n");
    printf("number of steps is %i\n", collatz(n));
}

int collatz(int n)
{
    if (n == 1)
        return 0;
    // even n
    else if (n % 2 == 0)
        return 1 + collatz(n/2);
    // odd n
    else
        return 1 + collatz(3*n + 1);
}
