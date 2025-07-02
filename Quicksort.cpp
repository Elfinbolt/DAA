#include<iostream>
using namespace std;
#define MAX 100

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // First element as pivot
    int i = low + 1;      // Index for elements greater than pivot
    int j = high;         // Index for elements less than pivot

    while (i <= j) {
        while (i <= high && arr[i] <= pivot) i++;
        while (j >= low && arr[j] > pivot) j--;

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    // Place pivot in the correct position
    swap(arr[low], arr[j]);
    return j;
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Main function
int main() {
    int i, n, arr[MAX];
    
    cout << "Enter the number of elements: ";
    cin >> n;
    
    for (i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << ": ";
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}