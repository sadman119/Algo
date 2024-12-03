#include <stdio.h>

// Function to sort items by value-to-weight ratio in descending order
void sortItemsByRatio(double ratio[], int values[], int weights[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                // Swap ratios
                double tempRatio = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempRatio;

                // Swap values
                int tempValue = values[j];
                values[j] = values[j + 1];
                values[j + 1] = tempValue;

                // Swap weights
                int tempWeight = weights[j];
                weights[j] = weights[j + 1];
                weights[j + 1] = tempWeight;
            }
        }
    }
}

// Function for Fractional Knapsack
double fractionalKnapsack(int values[], int weights[], int n, int capacity) {
    double ratio[n];
    double totalValue = 0.0;

    // Calculate value-to-weight ratio for each item
    for (int i = 0; i < n; i++) {
        ratio[i] = (double)values[i] / weights[i];
    }

    // Sort items by ratio in descending order
    sortItemsByRatio(ratio, values, weights, n);

    // Process each item
    for (int i = 0; i < n; i++) {
        if (capacity >= weights[i]) {
            // Take the whole item
            totalValue += values[i];
            capacity -= weights[i];
        } else {
            // Take a fraction of the item
            totalValue += ratio[i] * capacity;
            break; // Knapsack is full
        }
    }

    return totalValue;
}

int main() {
    int n, capacity;

    // Take user input for the number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int values[n], weights[n];

    // Take user input for values and weights
    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d - Value: ", i + 1);
        scanf("%d", &values[i]);
        printf("Item %d - Weight: ", i + 1);
        scanf("%d", &weights[i]);
    }

    // Take user input for the knapsack capacity
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    // Calculate the maximum value
    double maxValue = fractionalKnapsack(values, weights, n, capacity);

    // Output the result
    printf("Maximum value in the knapsack: %.2f\n", maxValue);

    return 0;
}
