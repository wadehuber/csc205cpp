// The methods in this class are adapted from the code provided with:
//   Java Foundations (2nd & 3rd ed) by Lewis, DePasquale, & Chase
//   Algorithms (4th ed) by Sedgewick & Wayne

#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <algorithm>   // std::max, std::min
#include "../jsjf/ArrayHeap.h"

// Sorting collects several generic sorting algorithms as static methods,
// mirroring the Java class.
//
// HEADER-ONLY TEMPLATE class (all methods are templates).
//
// Java used "<T extends Comparable<T>>" and called a.compareTo(b). C++
// templates are duck-typed, so we just require operator< / operator<= / >
// (which Contact, int, etc. provide). Java passed "T[] data" and read
// data.length; in C++ the public entry points take a reference to a sized
// array "T (&data)[N]" so the length N is deduced automatically, then delegate
// to pointer-based helpers (data, min, max).
class Sorting {
private:
    // Helper comparisons (Java used compareTo; here operator< / <= / >).
    template <typename T>
    static bool less_than(const T& a, const T& b) { return (a < b); }

    template <typename T>
    static bool less_than_equal(const T& a, const T& b) { return !(b < a); }  // a <= b

    template <typename T>
    static bool greater_than(const T& a, const T& b) { return (b < a); }      // a > b

    template <typename T>
    static void swap(T data[], int ii, int jj) {
        T tmp = data[ii];
        data[ii] = data[jj];
        data[jj] = tmp;
    }

public:
    // ---- isSorted ----
    template <typename T, int N>
    static bool isSorted(T (&data)[N]) {
        return isSorted(data, 0, N - 1);
    }

    template <typename T>
    static bool isSorted(T data[], int min, int max) {
        for (int ii = min + 1; ii <= max; ii++) {
            if (less_than(data[ii], data[ii - 1]))
                return false;
        }
        return true;
    }

    // ---- Selection Sort ----
    template <typename T, int N>
    static void selectionSort(T (&data)[N]) {
        selectionSort(data, 0, N - 1, N);
    }

    template <typename T>
    static void selectionSort(T data[], int min, int max, int length) {
        int indexOfSmallest;   // Smallest element found this pass

        min = std::max(min, 0);
        max = std::min(max, length - 1);

        // ii is the starting point for each pass
        for (int ii = min; ii <= max; ii++) {
            indexOfSmallest = ii;
            for (int scan = ii + 1; scan <= max; scan++) {
                if (less_than(data[scan], data[indexOfSmallest])) {
                    indexOfSmallest = scan;
                }
            }
            swap(data, indexOfSmallest, ii);
        }
    }

    // ---- Insertion Sort ----
    template <typename T, int N>
    static void insertionSort(T (&data)[N]) {
        insertionSort(data, 0, N - 1, N);
    }

    template <typename T>
    static void insertionSort(T data[], int min, int max, int length) {
        int start = std::max(min, 1);
        int end = std::min(max, length - 1);

        for (int index = start; index <= end; index++) {
            int position = index;

            // shift larger values to the right
            while (position > 0 && greater_than(data[position - 1], data[position])) {
                swap(data, position, position - 1);
                position--;
            }
        }
    }

    // ---- Bubble Sort ----
    template <typename T, int N>
    static void bubbleSort(T (&data)[N]) {
        bubbleSort(data, 0, N - 1, N);
    }

    template <typename T>
    static void bubbleSort(T data[], int min, int max, int length) {
        int position, scan;

        min = std::max(min, 0);
        max = std::min(max, length - 1);

        // position is the "stopping point" for each pass
        for (position = max; position >= min; position--) {
            for (scan = 0; scan < position; scan++) {
                if (greater_than(data[scan], data[scan + 1]))
                    swap(data, scan, scan + 1);
            }
        }
    }

    // ---- Merge Sort ----
    template <typename T, int N>
    static void mergeSort(T (&data)[N]) {
        mergeSort(data, 0, N - 1, N);
    }

private:
    template <typename T>
    static void mergeSort(T data[], int min, int max, int length) {
        if (min < max) {
            int mid = min + ((max - min) / 2);
            mergeSort(data, min, mid, length);
            mergeSort(data, mid + 1, max, length);
            merge(data, min, mid, max, length);
        }
    }

    template <typename T>
    static void merge(T data[], int first, int mid, int last, int length) {
        std::vector<T> temp(length);   // Java: new Comparable[data.length]

        // The two subarrays have already been sorted
        int first1 = first, last1 = mid;    // endpoints of first subarray
        int first2 = mid + 1, last2 = last; // endpoints of second subarray
        int index = first1;                 // next index open in temp array

        while (first1 <= last1 && first2 <= last2) {
            if (less_than(data[first1], data[first2])) {
                temp[index] = data[first1];
                first1++;
            }
            else {
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

        for (index = first; index <= last; index++)
            data[index] = temp[index];
    }

public:
    // ---- Quick Sort ----
    template <typename T, int N>
    static void quickSort(T (&data)[N]) {
        quickSort(data, 0, N - 1);
    }

private:
    template <typename T>
    static void quickSort(T data[], int min, int max) {
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
    static int partition(T data[], int min, int max) {
        T partitionelement;
        int left, right;
        int middle = min + ((max - min) / 2);

        // use the middle data value as the partition element
        partitionelement = data[middle];
        // move it out of the way for now
        swap(data, middle, min);

        left = min;
        right = max;

        while (left < right) {
            // search for an element that is > the partition element
            while (left < right && less_than_equal(data[left], partitionelement))
                left++;

            // search for an element that is < the partition element
            while (greater_than(data[right], partitionelement))
                right--;

            // swap the elements
            if (left < right)
                swap(data, left, right);
        }

        // move the partition element into place
        swap(data, min, right);

        return right;
    }

public:
    // ---- Heap Sort ----
    // Copies the array into a minheap, then pulls the elements back out in
    // sorted order via removeMin().
    template <typename T, int N>
    static void heapSort(T (&data)[N]) {
        ArrayHeap<T> heap;

        // copy the array into a heap
        for (int i = 0; i < N; i++)
            heap.addElement(data[i]);

        // place the sorted elements back into the array
        int count = 0;
        while (!(heap.isEmpty())) {
            data[count] = heap.removeMin();
            count++;
        }
    }
};

#endif
