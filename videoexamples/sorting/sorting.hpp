#ifndef SORTING_HPP
#define SORTING_HPP

#include <utility>

class Sorting {
private:
    static void swap(int& a, int& b);

public:
    static void selectionSort(int arr[], const int n);
    static void insertionSort(int arr[], const int n);
    static void bubbleSort(int arr[], const int n);
    static void mergeSort(int arr[], const int n);
    static void mergeSort(int arr[], const int start, const int end);
    static void merge(int arr[], const int l, const int m, const int r);
    static void quickSort(int arr[], const int n);
    static void quickSort(int arr[], const int low, const int high);
    static int partition(int arr[], const int low, const int high);
    static bool isSorted(int arr[], const int n);
};

#endif // SORTING_HPP