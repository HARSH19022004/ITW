#include <iostream>
#include <vector>

using namespace std;

// Function to heapify a subtree rooted at index 'i' in the vector 'arr' of size 'n'.
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;  // Initialize the root as the largest element.
    int left = 2 * i + 1; // Left child index
    int right = 2 * i + 2; // Right child index

    // If the left child is larger than the root.
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If the right child is larger than the largest so far.
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest element is not the root, swap them and recursively heapify the affected sub-tree.
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// Main function to perform heap sort on the vector 'arr'.
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build a max heap.
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements from the heap one by one.
    for (int i = n - 1; i > 0; i--) {
        // Move the current root to the end.
        swap(arr[0], arr[i]);
        // Call heapify on the reduced heap.
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int n = arr.size();

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    heapSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
