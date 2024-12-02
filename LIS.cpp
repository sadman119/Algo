#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find the Longest Increasing Subsequence (LIS)
int LIS(vector<int>& arr) {
    vector<int> dp(arr.size(), 1); // Initialize DP array with 1
    int maxLength = 1;

    for (size_t i = 1; i < arr.size(); i++) {
        for (size_t j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
        maxLength = max(maxLength, dp[i]);
    }
    return maxLength;
}

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60};
    cout << "Length of LIS: " << LIS(arr) << endl;
    return 0;
}
