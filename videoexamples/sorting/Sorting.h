#ifndef SORTING_H
#define SORTING_H

#include <vector>

class Sorting {
private:
    // Helper methods
    template <typename T>
    static bool lessThan(const T& a, const T& b) {
        return a < b;
    }

    template <typename T>
    static bool lessThanEqual(const T& a, const T& b) {
        return a <= b;
    }

    template <typename T>
    static bool greaterThan(const T& a, const T& b) {
        return a > b;
    }

    template <typename T>
    static void swap(std::vector<T>& data, int i, int j) {
        T temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }

    // Merge sort helper
    template <typename T>
    static void merge(std::vector<T>& data, int min, int mid, int max);

    // Quick sort helper
    template <typename T>
    static void quickSortHelper(std::vector<T>& data, int min, int max);

    template <typename T>
    static int partition(std::vector<T>& data, int min, int max);

public:
    // Check if array is sorted
    template <typename T>
    static bool isSorted(const std::vector<T>& data) {
        return isSorted(data, 0, data.size() - 1);
    }

    template <typename T>
    static bool isSorted(const std::vector<T>& data, int min, int max);

    // Selection Sort
    template <typename T>
    static void selectionSort(std::vector<T>& data) {
        selectionSort(data, 0, data.size() - 1);
    }

    template <typename T>
    static void selectionSort(std::vector<T>& data, int min, int max);

    // Insertion Sort
    template <typename T>
    static void insertionSort(std::vector<T>& data) {
        insertionSort(data, 0, data.size() - 1);
    }

    template <typename T>
    static void insertionSort(std::vector<T>& data, int min, int max);

    // Bubble Sort
    template <typename T>
    static void bubbleSort(std::vector<T>& data) {
        bubbleSort(data, 0, data.size() - 1);
    }

    template <typename T>
    static void bubbleSort(std::vector<T>& data, int min, int max);

    // Merge Sort
    template <typename T>
    static void mergeSort(std::vector<T>& data) {
        mergeSort(data, 0, data.size() - 1);
    }

    template <typename T>
    static void mergeSort(std::vector<T>& data, int min, int max);

    // Quick Sort
    template <typename T>
    static void quickSort(std::vector<T>& data) {
        quickSort(data, 0, data.size() - 1);
    }

    template <typename T>
    static void quickSort(std::vector<T>& data, int min, int max);
};

// Template implementations
template <typename T>
bool Sorting::isSorted(const std::vector<T>& data, int min, int max) {
    for (int i = min + 1; i <= max; i++) {
        if (lessThan(data[i], data[i - 1])) {
            return false;
        }
    }
    return true;
}

template <typename T>
void Sorting::selectionSort(std::vector<T>& data, int min, int max) {
    int indexOfSmallest;

    min = (min < 0) ? 0 : min;
    max = (max >= data.size()) ? data.size() - 1 : max;

    for (int next = min; next <= max; next++) {
        indexOfSmallest = next;
        for (int scan = next + 1; scan <= max; scan++) {
            if (lessThan(data[scan], data[indexOfSmallest])) {
                indexOfSmallest = scan;
            }
        }
        swap(data, indexOfSmallest, next);
    }
}

template <typename T>
void Sorting::insertionSort(std::vector<T>& data, int min, int max) {
    int start = (min < 0) ? 0 : min;
    int end = (max >= data.size()) ? data.size() - 1 : max;

    for (int current = start; current <= end; current++) {
        int position = current;

        while (position > start && greaterThan(data[position - 1], data[position])) {
            swap(data, position, position - 1);
            position--;
        }
    }
}

template <typename T>
void Sorting::bubbleSort(std::vector<T>& data, int min, int max) {
    int start = (min < 0) ? 0 : min;
    int end = (max >= data.size()) ? data.size() - 1 : max;

    for (int position = end; position >= start; position--) {
        for (int scan = 0; scan < position; scan++) {
            if (greaterThan(data[scan], data[scan + 1])) {
                swap(data, scan, scan + 1);
            }
        }
    }
}

template <typename T>
void Sorting::mergeSort(std::vector<T>& data, int min, int max) {
    if (min < max) {
        int mid = min + ((max - min) / 2);
        mergeSort(data, min, mid);
        mergeSort(data, mid + 1, max);
        merge(data, min, mid, max);
    }
}

template <typename T>
void Sorting::merge(std::vector<T>& data, int min, int mid, int max) {
    std::vector<T> temp(data.size());

    int first1 = min, last1 = mid;
    int first2 = mid + 1, last2 = max;
    int index = first1;

    while ((first1 <= last1) && (first2 <= last2)) {
        if (lessThan(data[first1], data[first2])) {
            temp[index] = data[first1];
            first1++;
        } else {
            temp[index] = data[first2];
            first2++;
        }
        index++;
    }

    while (first1 <= last1) {
        temp[index] = data[first1];
        first1++;
        index++;
    }

    while (first2 <= last2) {
        temp[index] = data[first2];
        first2++;
        index++;
    }

    for (index = min; index <= max; index++) {
        data[index] = temp[index];
    }
}

template <typename T>
void Sorting::quickSort(std::vector<T>& data, int min, int max) {
    quickSortHelper(data, min, max);
}

template <typename T>
void Sorting::quickSortHelper(std::vector<T>& data, int min, int max) {
    if (min < max) {
        int indexOfPartition = partition(data, min, max);
        quickSortHelper(data, min, indexOfPartition - 1);
        quickSortHelper(data, indexOfPartition + 1, max);
    }
}

template <typename T>
int Sorting::partition(std::vector<T>& data, int min, int max) {
    T partitionElement;
    int left = (min < 0) ? 0 : min;
    int right = (max >= data.size()) ? data.size() - 1 : max;

    int middle = min + ((max - min) / 2);
    partitionElement = data[middle];
    swap(data, middle, min);

    while (left < right) {
        while ((left < right) && lessThanEqual(data[left], partitionElement)) {
            left++;
        }
        while (greaterThan(data[right], partitionElement)) {
            right--;
        }
        if (left < right) {
            swap(data, left, right);
        }
    }

    swap(data, min, right);
    return right;
}

#endif
