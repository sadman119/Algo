#include <iostream>
#include <vector>
using namespace std;

// Function for Binary Search
int binarySearch(const vector<int>& arr, int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoids overflow
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
    vector<int> arr = {2, 4, 6, 8, 10, 12};
    int target = 8;
    int result = binarySearch(arr, 0, arr.size() - 1, target);
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;
    return 0;
}
