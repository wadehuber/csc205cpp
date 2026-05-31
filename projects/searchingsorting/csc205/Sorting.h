// The methods in this file are adapted from the code provided with:
//   Java Foundations (2nd & 3rd ed) by  Lewis, DePasquale, & Chase
//   Algorithms (4th ed) by Sedgewick & Wayne
//
// Java note: the Java version was a class "Sorting" with generic static
// methods (`<T extends Comparable<T>>`). In C++ the equivalent of a Java
// generic is a template, and templates must live entirely in a header file,
// so this is a HEADER-ONLY file (there is no Sorting.cpp). Instead of a class
// full of static methods we simply put free functions in a namespace-like
// struct so the calls read the same as Java: Sorting::sort(a), etc.
//
// Java compared elements with a.compareTo(b); here we use the ordinary C++
// operators <, <=, > on the element type T (so T must support them, just as
// Java required T to be Comparable).

#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <algorithm>   // std::max, std::min, std::swap

// We group the functions inside a struct named Sorting so callers write
// Sorting::sort(a) exactly like the Java Sorting.sort(a). Everything is
// static, matching the Java class of static methods.
struct Sorting {

    // ---------- Helper methods ----------
    // These operations occur multiple times in our sorting methods.
    // In Java these compared via compareTo; here we use plain operators.
    template <typename T>
    static bool less_than(const T& a, const T& b) {
        return (a < b);
    }
    template <typename T>
    static bool less_than_equal(const T& a, const T& b) {
        return (a <= b);
    }
    template <typename T>
    static bool greater_than(const T& a, const T& b) {
        return (a > b);
    }

    // Java's swap(Object[], i, j). We swap two elements of the vector.
    template <typename T>
    static void swap(std::vector<T>& a, int ii, int jj) {
        std::swap(a[ii], a[jj]);
    }

    template <typename T>
    static bool isSorted(const std::vector<T>& data) {
        return isSorted(data, 0, (int)data.size() - 1);
    }
    template <typename T>
    static bool isSorted(const std::vector<T>& data, int min, int max) {
        for (int ii = min + 1; ii <= max; ii++) {
            if (less_than(data[ii], data[ii - 1]))
                return false;
        }
        return true;
    }

    // ---------- Selection sort ----------
    template <typename T>
    static void selectionSort(std::vector<T>& data) {
        selectionSort(data, 0, (int)data.size() - 1);
    }
    template <typename T>
    static void selectionSort(std::vector<T>& data, int min, int max) {
        int indexOfSmallest;   // Index of the smallest element this pass

        // Make sure that min isn't too small and max isn't too big
        min = std::max(min, 0);
        max = std::min(max, (int)data.size() - 1);

        // next is the starting point for each pass
        // it is the index of where the smallest element will go
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

    // ---------- Insertion sort ----------
    template <typename T>
    static void insertionSort(std::vector<T>& data) {
        insertionSort(data, 0, (int)data.size() - 1);
    }
    template <typename T>
    static void insertionSort(std::vector<T>& data, int min, int max) {
        int start = std::max(min, 0);
        int end = std::min(max, (int)data.size() - 1);

        // Current is the length of the sorted sub-list at the start of the array
        for (int current = start; current <= end; current++) {
            int position = current;

            // shift larger values to the right
            while (position > start && greater_than(data[position - 1], data[position])) {
                swap(data, position, position - 1);
                position--;
            }
        }
    }

    // ---------- Bubble sort ----------
    template <typename T>
    static void bubbleSort(std::vector<T>& data) {
        bubbleSort(data, 0, (int)data.size() - 1);
    }
    template <typename T>
    static void bubbleSort(std::vector<T>& data, int min, int max) {
        int start = std::max(min, 0);
        int end = std::min(max, (int)data.size() - 1);

        int position, scan;

        // position is the "stopping point" for each pass
        for (position = end; position >= start; position--) {
            for (scan = 0; scan < position; scan++) {
                if (greater_than(data[scan], data[scan + 1])) {
                    swap(data, scan, scan + 1);
                }
            }
        }
    }

    // ---------- Merge sort ----------
    template <typename T>
    static void mergeSort(std::vector<T>& data) {
        mergeSort(data, 0, (int)data.size() - 1);
    }
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

        // Java made a temp array: (T[])(new Comparable[data.length]).
        // In C++ we use a std::vector<T> of the same length.
        std::vector<T> temp(data.size());   // temp array

        //      Half 1            Half 2
        // [min| .... |mid][mid+1| .... |max]
        int first1 = min,   last1 = mid;    // endpoints of the first subarray
        int first2 = mid + 1, last2 = max;  // endpoints of the second subarray
        int index = first1;                 // index into the temp array

        // Copy the smaller item from each subarray until one of the subarrays is empty

        // While both subarrays have at least one item left
        while ((first1 <= last1) && (first2 <= last2)) {
            if (less_than(data[first1], data[first2])) {
                // Move first1 to the temp array
                temp[index] = data[first1];
                first1++;
            } else {
                // Move first2 to the temp array
                temp[index] = data[first2];
                first2++;
            }
            index++;  // Move to the next available cell in the temp array
        }

        // At this point one of the subarrays is empty
        // Copy the remaining elements to temp - only one of these loops will run
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

        // Copy the merged data into the original array
        for (index = min; index <= max; index++) {
            data[index] = temp[index];
        }
    }

    // ---------- Quick sort ----------
    template <typename T>
    static void quickSort(std::vector<T>& data) {
        quickSort(data, 0, (int)data.size() - 1);
    }
    template <typename T>
    static void quickSort(std::vector<T>& data, int min, int max) {
        if (min < max) {
            // Create a partition
            int indexOfPartition = partition(data, min, max);

            // sort the left partition (lower values)
            quickSort(data, min, indexOfPartition - 1);

            // sort the right partition (higher values)
            quickSort(data, indexOfPartition + 1, max);
        }
    }
    template <typename T>
    static int partition(std::vector<T>& data, int min, int max) {
        T partitionElement;
        int left = std::max(min, 0);
        int right = std::min(max, (int)data.size() - 1);

        // Use the middle data as the partition element
        int middle = min + ((max - min) / 2);
        partitionElement = data[middle];
        // move the middle element out of the way for now
        swap(data, middle, min);

        while (left < right) {
            // search for an element that is > than the partition element
            while ((left < right) && (less_than_equal(data[left], partitionElement))) {
                left++;
            }
            // search for an element that is < the partition element
            while (greater_than(data[right], partitionElement)) {
                right--;
            }
            // swap the elements at left & right
            if (left < right) {
                swap(data, left, right);
            }
        }

        // move the partition element back into place
        // right will be the index of the partition element
        swap(data, min, right);
        return right;
    }

    // ---------- Project 7 (student stubs) ----------
    // These are intentionally left unfinished, exactly as in the Java starter
    // code, to be completed as part of the programming project.

    template <typename T>
    static void sort(std::vector<T>& data) {
        // To be completed as part of Programming Project
        (void)data;   // silence "unused parameter" warning while the body is empty
    }

    template <typename T>
    static void cutoffQsort(std::vector<T>& data) {
        // To be completed as part of Programming Project
        (void)data;
    }
    template <typename T>
    static void cutoffQsort(std::vector<T>& data, int min, int max) {
        // To be completed as part of Programming Project
        (void)data;
        (void)min;
        (void)max;
    }

    // Java returned List<Integer> and the stub returned null.
    // C++ does not have a "null list" the way Java does, so the stub returns
    // an empty std::vector<int>. The driver prints this as "[]".
    static std::vector<int> closestPair(const std::vector<int>& data) {
        // To be completed as part of Programming Project
        (void)data;
        return std::vector<int>();   // Java returned null
    }

    // Java returned List<T> and the stub returned null.
    // C++ stub returns an empty std::vector<T> instead; the driver prints "[]".
    template <typename T>
    static std::vector<T> firstN(const std::vector<T>& data, int n) {
        // To be completed as part of Programming Project
        (void)data;
        (void)n;
        return std::vector<T>();   // Java returned null
    }
};

#endif // SORTING_H
