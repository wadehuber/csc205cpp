#include <iostream>
#include <vector>
#include <random>
#include "Sorting.h"

enum SortType { SELECTION, INSERTION, BUBBLE, MERGE, QUICK };

void printArray(const std::vector<int>& a);

int main() {
    std::vector<int> a(100);
    std::mt19937 rand(std::random_device{}());
    std::uniform_int_distribution<> dis(0, 999);

    int failures = 0;
    SortType sortType = INSERTION;

    for (int kk = 0; kk < 500; kk++) {
        for (int ii = 0; ii < a.size(); ii++) {
            a[ii] = dis(rand);
        }

        std::cout << "\nUnsorted: ";
        printArray(a);

        if (sortType == INSERTION) {
            Sorting::insertionSort(a);
        }

        std::cout << "  Sorted: ";
        printArray(a);

        if (!Sorting::isSorted(a)) {
            std::cout << "Fail!\n";
            failures++;
        }
    }

    std::cout << "\n";
    if (failures == 0) {
        std::cout << "Test successful! (" << failures << " failures)\n";
    } else {
        std::cout << "Test unsuccessful! (" << failures << " failures)\n";
    }

    return 0;
}

void printArray(const std::vector<int>& a) {
    for (int ii = 0; ii < a.size(); ii++) {
        std::cout << a[ii] << " ";
    }
    std::cout << "\n";
}
