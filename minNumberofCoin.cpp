#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate minimum coins
void minCoins(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend()); // Sort coins in descending order
    int count = 0;
    for (int coin : coins) {
        if (amount == 0) break;
        count += amount / coin;
        amount %= coin;
    }
    cout << "Minimum coins required: " << count << endl;
}

int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int amount = 93;
    minCoins(coins, amount);
    return 0;
}
