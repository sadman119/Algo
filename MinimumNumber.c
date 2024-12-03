#include <stdio.h>
int main() {
       int no_of_coin;
    scanf("%d",&no_of_coin);
    int coins[no_of_coin];
    //Input all the coins value
    for(int i = 0; i<no_of_coin; i++)
        scanf("%d", &coins[i]);
    int value;
    scanf("%d",&value); // what is the value that you want to make
    int min_coin = 0;

    for(int i = no_of_coin-1 ; i>=0; i--)
    {
        if(value == 0) break;
        if(value >= coins[i])
        {
            min_coin = min_coin + (int)(value / coins[i]);
            value = value % coins[i];
        }

    }
    if(value == 0)
        printf("Minimum number of coins using Greedy = %d\n", min_coin);
    else
        printf("Greedy says not possible\n");

    return 0;
}
