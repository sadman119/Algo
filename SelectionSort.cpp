#include <iostream>
#include <vector>
using namespace std;

// Function for Selection Sort
void selectionSort(vector<int>& arr) {
    for (size_t i = 0; i < arr.size() - 1; i++) {
        int minIndex = i;
        for (size_t j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    vector<int> arr = {64, 25, 12, 22, 11};
    selectionSort(arr);
    cout << "Sorted array: ";
    for (int num : arr)
        cout << num << " ";
    return 0;
}
