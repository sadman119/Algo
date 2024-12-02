#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Item structure
struct Item {
    int value, weight;
};

// Function for Fractional Knapsack
double fractionalKnapsack(vector<Item>& items, int W) {
    sort(items.begin(), items.end(), [](Item a, Item b) {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    });

    double maxValue = 0.0;
    for (auto& item : items) {
        if (W >= item.weight) {
            W -= item.weight;
            maxValue += item.value;
        } else {
            maxValue += (double)item.value * W / item.weight;
            break;
        }
    }
    return maxValue;
}

int main() {
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    int W = 50;
    cout << "Maximum value: " << fractionalKnapsack(items, W) << endl;
    return 0;
}
