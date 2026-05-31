#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <algorithm>   // std::max, std::min

// The methods in this package are adapted from the code provided with:
//   Java Foundations (2nd & 3rd ed) by Lewis, DePasquale, & Chase
//   Algorithms (4th ed) by Sedgewick & Wayne
//
// HEADER-ONLY TEMPLATE. Java had a class with generic static methods
// (<T extends Comparable<T>>). In C++ we make Sorting a class with static
// member function templates; callers write Sorting::bstSort(data) just like
// the Java Sorting.bstSort(data).
//
// COMPARABLE: Java's a.compareTo(b) becomes the C++ comparison operators
// (operator< / operator<= / operator>) on T. Any element type used here must
// define those (int already does).
//
// ARRAYS: Java used T[] arrays. We use std::vector<T>& so the data can be
// resized/queried with .size() and passed by reference (mirroring how Java
// arrays are passed by reference).
class Sorting {
private:
    // Helper methods. These operations occur multiple times in our sorting
    // methods, so we add methods for them here.
    template <typename T>
    static bool less_than(const T& a, const T& b) {
        return (a < b);   // Java: a.compareTo(b) < 0
    }
    template <typename T>
    static bool less_than_equal(const T& a, const T& b) {
        return (a <= b);   // Java: a.compareTo(b) <= 0
    }
    template <typename T>
    static bool greater_than(const T& a, const T& b) {
        return (a > b);   // Java: a.compareTo(b) > 0
    }
    template <typename T>
    static void swap(std::vector<T>& a, int ii, int jj) {
        T swapVal = a[ii];
        a[ii] = a[jj];
        a[jj] = swapVal;
    }

public:
    template <typename T>
    static bool isSorted(std::vector<T>& data) {
        return isSorted(data, 0, (int) data.size() - 1);
    }
    template <typename T>
    static bool isSorted(std::vector<T>& data, int min, int max) {
        for (int ii = min + 1; ii <= max; ii++) {
            if (less_than(data[ii], data[ii - 1]))
                return false;
        }
        return true;
    }

    // Selection Sort
    template <typename T>
    static void selectionSort(std::vector<T>& data) {
        selectionSort(data, 0, (int) data.size() - 1);
    }

    template <typename T>
    static void selectionSort(std::vector<T>& data, int min, int max) {
        int indexOfSmallest;   // Index of the smallest element this pass

        // Make sure min isn't too small and max isn't too big
        min = std::max(min, 0);
        max = std::min(max, (int) data.size() - 1);

        // next is the starting point for each pass (where the next smallest
        //  element will go)
        for (int next = min; next <= max; next++) {
            indexOfSmallest = next;
            for (int scan = next + 1; scan <= max; scan++) {
                if (less_than(data[scan], data[indexOfSmallest])) {
                    indexOfSmallest = scan;
                }
            }
            swap(data, indexOfSmallest, next);
        }
    }

    template <typename T>
    static void insertionSort(std::vector<T>& data) {
        insertionSort(data, 0, (int) data.size() - 1);
    }

    template <typename T>
    static void insertionSort(std::vector<T>& data, int min, int max) {
        int start = std::max(min, 1);
        int end = std::min(max, (int) data.size() - 1);

        // Current is the length of the sorted sub-list at the start of the array
        for (int current = start; current <= end; current++) {
            int position = current;

            // shift larger values to the right
            while (position > 0 && greater_than(data[position - 1], data[position])) {
                swap(data, position, position - 1);
                position--;
            }
        }
    }

    template <typename T>
    static void bubbleSort(std::vector<T>& data) {
        bubbleSort(data, 0, (int) data.size() - 1);
    }
    template <typename T>
    static void bubbleSort(std::vector<T>& data, int min, int max) {
        int position, scan;

        int start = std::max(min, 1);
        int end = std::min(max, (int) data.size() - 1);

        // position is the "stopping point" for each pass
        for (position = end; position >= start; position--) {
            for (scan = 0; scan < position; scan++) {
                if (greater_than(data[scan], data[scan + 1])) {
                    swap(data, scan, scan + 1);
                }
            }
        }
    }

    template <typename T>
    static void mergeSort(std::vector<T>& data) {
        mergeSort(data, 0, (int) data.size() - 1);
    }

private:
    template <typename T>
    static void mergeSort(std::vector<T>& data, int min, int max) {
        if (min < max) {
            int mid = min + ((max - min) / 2);
            mergeSort(data, min, mid);
            mergeSort(data, mid + 1, max);
            merge(data, min, mid, max);
        }
    }

    template <typename T>
    static void merge(std::vector<T>& data, int min, int mid, int max) {
        std::vector<T> temp(data.size());   // temp array

        // The two subarrays have already been sorted
        int first1 = min, last1 = mid;     // endpoints of the first subarray
        int first2 = mid + 1, last2 = max; // endpoints of the second subarray
        int index = first1;                // next index open in temp array

        // Copy the smaller item from each subarray until one subarray is empty

        // While both subarrays have items left
        while ((first1 <= last1) && (first2 <= last2)) {
            if (less_than(data[first1], data[first2])) {
                // Move first1 to the temp array
                temp[index] = data[first1];
                first1++;
            }
            else {
                // Move first2 to the temp array
                temp[index] = data[first2];
                first2++;
            }
            index++;  // Move the index of the next available cell in the temp array
        }

        // Only one of the while loops below will execute

        // Copy the remaining elements from the first subarray, if any
        while (first1 <= last1) {
            temp[index] = data[first1];
            first1++;
            index++;
        }

        // Copy the remaining elements from the second subarray, if any
        while (first2 <= last2) {
            temp[index] = data[first2];
            first2++;
            index++;
        }

        // Copy merged data into original array
        for (index = min; index <= max; index++) {
            data[index] = temp[index];
        }
    }

public:
    template <typename T>
    static void quickSort(std::vector<T>& data) {
        quickSort(data, 0, (int) data.size() - 1);
    }

private:
    template <typename T>
    static void quickSort(std::vector<T>& data, int min, int max) {
        if (min < max) {
            // create partitions
            int indexofpartition = partition(data, min, max);

            // sort the left partition (lower values)
            quickSort(data, min, indexofpartition - 1);

            // sort the right partition (higher values)
            quickSort(data, indexofpartition + 1, max);
        }
    }

    template <typename T>
    static int partition(std::vector<T>& data, int min, int max) {
        T partitionElement;
        int left, right;
        int middle = min + ((max - min) / 2);

        // use the middle data value as the partition element
        partitionElement = data[middle];
        // move the middle element out of the way for now
        swap(data, middle, min);

        left = std::max(min, 0);
        right = std::min(max, (int) data.size() - 1);
        while (left < right) {
            // search for an element that is > the partition element
            while ((left < right) && (less_than_equal(data[left], partitionElement))) {
                left++;
            }
            // search for an element that is < the partition element
            while (greater_than(data[right], partitionElement)) {
                right--;
            }
            // swap the elements
            if (left < right) {
                swap(data, left, right);
            }
        }

        // move the partition element back into place
        // right will be the index of the partition element
        swap(data, min, right);

        return right;
    }

public:
    // Project 8 - Complete the following method
    template <typename T>
    static void bstSort(std::vector<T>& data) {
        // Project 8
        // (Stub: intentionally left unimplemented, exactly as the Java starter.)
        (void) data;
    }
};

#endif
