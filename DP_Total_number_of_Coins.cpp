#include <iostream>
#include <vector>
using namespace std;

int totalWays(vector<int>& coins, int target) {
    // Create a DP array initialized with 0
    vector<int> dp(target + 1, 0);

    // Base case: There's one way to make target 0 (using no coins)
    dp[0] = 1;

    // Iterate over each coin using a normal for loop
    for (int i = 0; i < coins.size(); ++i) {
        int coin = coins[i]; // Current coin
        // Update DP table for every value >= coin
        for (int j = coin; j <= target; ++j) {
            dp[j] += dp[j - coin];
        }
    }

    return dp[target];
}

int main() {
    // Input: Array of coins and target value
    vector<int> coins = {1, 2, 3}; // Example coin denominations
    int target = 4;               // Target sum

    // Calculate the total number of ways
    int result = totalWays(coins, target);

    // Output the result
    cout << "Total number of ways to make " << target << ": " << result << endl;

    return 0;
}
