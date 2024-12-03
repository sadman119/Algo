#include <stdio.h>

// Function for 0/1 Knapsack
int knapsack(int weights[], int values[], int n, int W) {
    int dp[n + 1][W + 1]; // DP table to store solutions to subproblems

    // Initialize DP table with 0s
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = 0;
        }
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // Compare including the item and excluding the item
                int include = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                int exclude = dp[i - 1][w];
                dp[i][w] = (include > exclude) ? include : exclude; // Take maximum
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W]; // Return the maximum value that can be obtained
}

int main() {
    int n, W;

    // Take user input for the number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];

    // Take user input for the weights and values of items
    printf("Enter the weights of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    printf("Enter the values of the items: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    // Take user input for the capacity of the knapsack
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);

    // Call the knapsack function and print the result
    printf("Maximum value in Knapsack: %d\n", knapsack(weights, values, n, W));

    return 0;
}
