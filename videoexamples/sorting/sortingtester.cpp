#include "sorting.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

enum class SortType { SELECTION, INSERTION, BUBBLE, MERGE, QUICK };

void printArray(int arr[], const int n) {
    for (int ii = 0; ii < n; ii++) {
        std::cout << arr[ii] << " ";
    }
    std::cout << "\n";
}

int main() {
    const int size = 10;
    int a[size];
    int failures = 0;

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    SortType sortTypes[] = { SortType::SELECTION, SortType::INSERTION, 
                             SortType::BUBBLE, SortType::MERGE, SortType::QUICK };
    const int numSorts = sizeof(sortTypes) / sizeof(sortTypes[0]);

    for (int ii = 0; ii < numSorts; ii++) {
        for (int jj = 0; jj < size; jj++) {
            a[jj] = std::rand() % 1000;
        }

        std::cout << "\nTesting ";
        switch (sortTypes[ii]) {
            case SortType::SELECTION: std::cout << "Selection Sort"; break;
            case SortType::INSERTION: std::cout << "Insertion Sort"; break;
            case SortType::BUBBLE: std::cout << "Bubble Sort"; break;
            case SortType::MERGE: std::cout << "Merge Sort"; break;
            case SortType::QUICK: std::cout << "Quick Sort"; break;
        }
        std::cout << ":\nUnsorted: ";
        printArray(a, size);

        switch (sortTypes[ii]) {
            case SortType::SELECTION:
                Sorting::selectionSort(a, size);
                break;
            case SortType::INSERTION:
                Sorting::insertionSort(a, size);
                break;
            case SortType::BUBBLE:
                Sorting::bubbleSort(a, size);
                break;
            case SortType::MERGE:
                Sorting::mergeSort(a, 0, size - 1); 
                break;
            case SortType::QUICK:
                Sorting::quickSort(a, 0, size - 1);
                break;
        }

        std::cout << "  Sorted: ";
        printArray(a, size);

        if (!Sorting::isSorted(a, size)) {
            std::cout << "Fail!\n";
            failures++;
        }
    }

    std::cout << "\n";
    if (failures == 0) {
        std::cout << "All tests successful! (" << failures << " failures)\n";
    } else {
        std::cout << "Tests unsuccessful! (" << failures << " failures)\n";
    }

    return 0;
}