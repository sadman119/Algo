#include <iostream>
#include <vector>
using namespace std;

// Function for Bubble Sort
void bubbleSort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        for (size_t j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}

int main() {
    vector<int> arr = {5, 1, 4, 2, 8};
    bubbleSort(arr);
    cout << "Sorted array: ";
    for (size_t i = 0; i < arr.size(); ++i)
    cout << arr[i] << " ";

    return 0;
}
