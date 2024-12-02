#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the total number of ways to make change
int totalWays(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1; // Base case: one way to make amount 0

    for (int c = 0; c < coins.size(); c++) { // Iterate over each coin
        for (int i = coins[c]; i <= amount; i++) { // Iterate over possible amounts
            dp[i] += dp[i - coins[c]];
        }
    }
    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    cout << "Total number of ways to make change: " << totalWays(coins, amount) << endl;
    return 0;
}
