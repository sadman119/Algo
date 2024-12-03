#include <stdio.h>

// Function for Binary Search
int binarySearch(const int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoid overflow
        if (arr[mid] == target)
            return mid; // Target found
        else if (arr[mid] < target)
            low = mid + 1; // Search in the right half
        else
            high = mid - 1; // Search in the left half
    }
    return -1; // Target not found
}

int main() {
    int n, target;

    // Input array size
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n]; // Declare array

    // Input array elements
    printf("Enter %d sorted elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the target element to search
    printf("Enter the target element: ");
    scanf("%d", &target);

    // Perform binary search
    int result = binarySearch(arr, 0, n - 1, target);

    // Output the result
    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
