#include <stdio.h>

// Function for Fractional Knapsack
double fractionalKnapsack(int n, int W) {
    double maxValue = 0.0;
    for (int i = 0; i < n; i++) {
        int value, weight;
        double ratio;
        
        // Taking user input for value and weight of each item
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &value, &weight);
        
        // Calculate the value-to-weight ratio
        ratio = (double)value / weight;
        
        // Check if the item can be fully taken
        if (W >= weight) {
            W -= weight;
            maxValue += value;
        } else {
            // If the item can't be fully taken, take the fractional part
            maxValue += (double)value * W / weight;
            break;  // No more weight capacity left
        }
    }
    
    return maxValue;
}

int main() {
    int n, W;
    
    // Take user input for the number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Take user input for the maximum weight capacity of the knapsack
    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);

    // Call the function and output the result
    printf("Maximum value that can be obtained: %.2lf\n", fractionalKnapsack(n, W));

    return 0;
}
