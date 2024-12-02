#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the Longest Common Subsequence (LCS)
int LCS(const string& s1, const string& s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int main() {
    string s1 = "AGGTAB", s2 = "GXTXAYB";
    cout << "Length of LCS: " << LCS(s1, s2) << endl;
    return 0;
}
