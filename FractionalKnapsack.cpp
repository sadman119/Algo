#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function for Fractional Knapsack
double fractionalKnapsack(vector<int>& values, vector<int>& weights, int W) {
    int n = values.size();
    vector<pair<double, int>> valuePerWeight(n);

    // Calculate value-to-weight ratio for each item
    for (int i = 0; i < n; ++i) {
        valuePerWeight[i] = {(double)values[i] / weights[i], i};
    }

    // Sort items by value-to-weight ratio in descending order
    sort(valuePerWeight.begin(), valuePerWeight.end(), [](pair<double, int> a, pair<double, int> b) {
        return a.first > b.first;
    });

    double maxValue = 0.0;

    // Iterate through items using a normal for loop
    for (int i = 0; i < n; ++i) {
        int idx = valuePerWeight[i].second;
        if (W >= weights[idx]) {
            W -= weights[idx];
            maxValue += values[idx];
        } else {
            maxValue += (double)values[idx] * W / weights[idx];
            break;
        }
    }

    return maxValue;
}

int main() {
    // Arrays for values and weights
    vector<int> values = {60, 100, 120};
    vector<int> weights = {10, 20, 30};
    int W = 50;

    // Call the function and output the result
    cout << "Maximum value: " << fractionalKnapsack(values, weights, W) << endl;
    return 0;
}
