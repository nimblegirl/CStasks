// validates credit cards

#include <stdio.h>
#include <cs50.h>

bool isCardValid(long card);
long getCard();
int getDigitCount(long n);
int sumDoubledEven(long n);
int sumOdd(long n);
int getCardPrefix(long n);

void program();

void tests();
bool test(int testId, long card, int ePrefix, int eCount, int eSumO, int eSumDE, bool eIsValid);

int main(void) 
{
    tests();    
    //program();
    
    return 0;
}

void program()
{
    long card = getCard();
    bool isValid = isCardValid(card);  
    if(getDigitCount(card) >= 13 && getDigitCount(card) <= 16 && isValid)
    {
        if (getCardPrefix(card) == 34 || getCardPrefix(card) == 37)
        {
            printf("AMEX\n");
        } 
        else if (getCardPrefix(card) >= 51 && getCardPrefix(card) <= 55)
        {
            printf("MASTERCARD\n");
        }
        else if (getCardPrefix(card) >= 40 && getCardPrefix(card) < 50)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n"); 
        }
    }
    else
    {
        printf("INVALID\n"); 
    }
}

void tests()
{
    printf("TESTS...\n");
    bool pass = true;
    pass &= test(1, 378282246310005, 37, 15, 33, 27, true);
    pass &= test(2, 37873449367101, 37, 14, 35, 38, false);
    pass &= test(4, 340095774092570, 34, 15, 37, 23, true);
    pass &= test(5, 4111111111111111, 41, 16, 8, 22, true);
    pass &= test(6, 5555555555554444, 55, 16, 38, 22, true);
    pass &= test(7, 30569309025904, 30, 14, 33, 17, true);
    
    if(pass)
    {
        printf("ALL TESTS PASSED \n");
    }
    else
    {
        printf("FAILED \n");
    }
}

bool test(int testId, long card, int ePrefix, int eCount, int eSumO, int eSumDE, bool eIsValid)
{
    printf("Test: %i - %li\n", testId, card);
    
    bool pass = true;
        
    int aPrefix = getCardPrefix(card);
    if(aPrefix != ePrefix && ePrefix != -1)
    {
        pass = false;
        printf("Prefix bug - %d : %d \n", ePrefix, aPrefix);
    }     
    
    int aCount = getDigitCount(card);
    if(aCount != eCount && eCount != -1)
    {
        pass = false;
        printf("Count bug - %d : %d \n", eCount, aCount);
    }      
    
    int aSumO = sumOdd(card);
    if(aSumO != eSumO && eSumO != -1)
    {
        pass = false;
        printf("Sum Odd bug - %d : %d \n", eSumO, aSumO);
    }
    
    int aSumDE = sumDoubledEven(card);
    if(aSumDE != eSumDE && eSumDE != -1)
    {
        pass = false;
        printf("Sum Doubled Even bug - %d : %d \n", eSumDE, aSumDE);
    }
    
    int aIsValid = isCardValid(card);
    if(aIsValid != eIsValid)
    {
        pass = false;
        printf("Result bug - %d : %d \n", eIsValid, aIsValid);
    }
    
    if(pass)
    {
        printf("OK \n\n");
    }
    else
    {
        printf("FAIL \n\n");
    }
    
    return pass;
}

long getCard()
{
    long n;
    int count;
    do
    {
        count = 0;
        n = get_long("Enter number: ");
        count = getDigitCount(n);  
        printf("INVALID\n");
    }
    while (count < 0);
    return n;
}

int getDigitCount(long n)
{
    int count = 0;
    while (n != 0) 
    {
        n = n / 10;
        count++;
    }  
    return count;
}

bool isCardValid(long card)
{
    int total = sumDoubledEven(card) + sumOdd(card);
    printf("Checksum %i\n", total);    
    
    return total % 10 == 0;
}

int sumDoubledEven(long n)
{
    int sum = 0;
    int temp = 0;
    n = n / 10;
    while (n > 0)
    {
        temp = n % 10;
        temp *= 2;
        if (temp > 9) {
            temp -= 9;
        }
        sum += temp;
        n = n / 100;
    }
    return sum;
}

int sumOdd(long n)
{
    int sum = 0;
    while (n > 0) {
        sum += (int)(n % 10);
        n = n / 100;
    }
    return sum;
}

int getCardPrefix(long n)
{
    long prefix = n;
    while (prefix >= 100)
    {
        prefix /= 10;
    }
    return prefix;
}
