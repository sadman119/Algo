#include <stdio.h>

// Function to calculate the total number of ways to make the target value
int totalWays(int coins[], int n, int target) {
    int dp[target + 1];  // Array to store the number of ways to reach each sum
    dp[0] = 1;           // There's one way to make target 0 (using no coins)

    // Initialize the rest of the dp array with 0
    for (int i = 1; i <= target; i++) {
        dp[i] = 0;
    }

    // Iterate over each coin
    for (int i = 0; i < n; i++) {
        int coin = coins[i];  // Current coin
        // Update the dp table for every value >= coin
        for (int j = coin; j <= target; j++) {
            dp[j] += dp[j - coin];
        }
    }

    return dp[target];  // Return the total number of ways to make the target sum
}

int main() {
    int n, target;

    // Take user input for the number of coin denominations
    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);

    int coins[n];

    // Take user input for the coin denominations
    printf("Enter the coin denominations: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    // Take user input for the target sum
    printf("Enter the target sum: ");
    scanf("%d", &target);

    // Calculate the total number of ways to make the target sum
    int result = totalWays(coins, n, target);

    // Output the result
    printf("Total number of ways to make %d: %d\n", target, result);

    return 0;
}
