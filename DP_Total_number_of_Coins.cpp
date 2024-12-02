#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the total number of ways to make change
int totalWays(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1; // Base case: one way to make amount 0

    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
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
