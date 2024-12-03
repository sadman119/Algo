#include <stdio.h>

// Function to calculate minimum coins
void minCoins(int coins[], int n, int amount) {
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (amount == 0) break;
        
        // If the coin is smaller than or equal to the remaining amount
        if (coins[i] <= amount) {
            count += amount / coins[i];  // Add the number of coins of this denomination
            amount %= coins[i];          // Update the remaining amount
        }
    }

    // If we are able to form the amount, print the result
    if (amount == 0)
        printf("Minimum coins required: %d\n", count);
    else
        printf("Amount cannot be formed with the given coins\n");
}

int main() {
    int n;

    // Take user input for the number of coin denominations
    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);

    int coins[n];

    // Take user input for the coin denominations
    printf("Enter the coin denominations:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    // Take user input for the amount
    int amount;
    printf("Enter the amount: ");
    scanf("%d", &amount);

    // Call the function to calculate the minimum coins
    minCoins(coins, n, amount);

    return 0;
}
