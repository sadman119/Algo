#include <iostream>
#include <vector>
using namespace std;

// Function for Insertion Sort
void insertionSort(vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    insertionSort(arr);
    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    return 0;
}
