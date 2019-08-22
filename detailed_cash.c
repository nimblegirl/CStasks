#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main() {
    float dollars;
    int coins, i = 0;
    int coin_set[4] = {25, 10, 5, 1};
    int cents;
    int total_coins = 0;
    
    do {
        dollars = get_float("Please, enter amount of change: ");
    }
    while (dollars <= 0);
    
    cents = round(dollars * 100);
    
    while (i < sizeof(coin_set)/sizeof(coin_set[0])) {
        if (coin_set[i] <= cents) {
            coins = cents / coin_set[i];
            
            if (coin_set[i] == 25) {
                printf("%i of quarters (%i c) \n", coins, coin_set[i]);
            }
            if (coin_set[i] == 10) {
                printf("%i of dimes (%i c) \n", coins, coin_set[i]);
            }
            if (coin_set[i] == 5) {
                printf("%i of nickels (%i c) \n", coins, coin_set[i]);
            }
            if (coin_set[i] == 1) {
                printf("%i of pennies (%i c) \n", coins, coin_set[i]);
            }
            
            cents = cents - coins * coin_set[i];
            total_coins += coins;
        }
        i++;
    }
    printf("--------------\n");
    printf("total coins %i \n", total_coins);
}
