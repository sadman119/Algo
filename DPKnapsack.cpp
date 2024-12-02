#include <iostream>
#include <vector>
using namespace std;

// Function for 0/1 Knapsack
int knapsack(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main() {
    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};
    int W = 50;
    cout << "Maximum value in Knapsack: " << knapsack(weights, values, W) << endl;
    return 0;
}