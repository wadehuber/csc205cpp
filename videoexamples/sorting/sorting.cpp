#include "sorting.hpp"

bool Sorting::isSorted(int arr[], const int n) {
    for (int ii = 0; ii < n - 1; ii++) {
        if (arr[ii] > arr[ii + 1]) {
            return false;
        }
    }
    return true;
}

void Sorting::selectionSort(int arr[], const int n) {
    for (int ii = 0; ii < n - 1; ii++) {
        int min_idx = ii;
        for (int jj = ii + 1; jj < n; jj++) {
            if (arr[jj] < arr[min_idx]) {
                min_idx = jj;
            }
        }
        std::swap(arr[min_idx], arr[ii]);
    }
}

void Sorting::insertionSort(int arr[], const int n) {
    for (int ii = 1; ii < n; ii++) {
        int key = arr[ii];
        int jj = ii - 1;
        while (jj >= 0 && arr[jj] > key) {
            arr[jj + 1] = arr[jj];
            jj--;
        }
        arr[jj + 1] = key;
    }
}

void Sorting::bubbleSort(int arr[], const int n) {
    bool swapped; // Flag to check if a swap occurred
    for (int ii = 0; ii < n - 1; ii++) {
        swapped = false;
        for (int jj = 0; jj < n - ii - 1; jj++) {
            if (arr[jj] > arr[jj + 1]) {
                std::swap(arr[jj], arr[jj + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;  // No swaps means the array is sorted
    }
}

void Sorting::mergeSort(int arr[], const int n) {
    mergeSort(arr, 0, n - 1); 
}

void Sorting::mergeSort(int arr[], const int start, const int end) {
    if (start < end) {
        int mid = start + (end - start) / 2; 
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void Sorting::merge(int arr[], const int l, const int m, const int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    
    int* leftside = new int[n1];
    int* rightside = new int[n2];

    for (int ii = 0; ii < n1; ii++) {
        leftside[ii] = arr[l + ii];
    }
    for (int jj = 0; jj < n2; jj++) {
        rightside[jj] = arr[m + 1 + jj];
    }
    
    int ii = 0, jj = 0, kk = l;
    while (ii < n1 && jj < n2) {
        arr[kk++] = (leftside[ii] <= rightside[jj]) ? leftside[ii++] : rightside[jj++];
    }
    while (ii < n1) {
        arr[kk++] = leftside[ii++];
    }
    while (jj < n2) {
        arr[kk++] = rightside[jj++];
    }
    
    delete[] leftside;
    delete[] rightside;
}

void Sorting::quickSort(int arr[], const int n) {
    quickSort(arr, 0, n - 1); 
}

void Sorting::quickSort(int arr[], const int low, const int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int Sorting::partition(int arr[], const int low, const int high) {
    int pivot = arr[high];
    int ii = low - 1;
    
    for (int jj = low; jj < high; jj++) {
        if (arr[jj] < pivot) {
            ii++;
            std::swap(arr[ii], arr[jj]);
        }
    }
    std::swap(arr[ii + 1], arr[high]);
    return ii + 1;
}
