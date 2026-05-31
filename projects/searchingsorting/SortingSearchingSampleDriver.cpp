#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <sstream>

#include "cards/Deck.h"
#include "csc205/Sorting.h"

const int LENGTH = 30;

// ----------- Helper functions --------------

// Java: printArray(Object[] a) printed each element followed by a space.
// We template it so it works for a vector of any printable type.
template <typename T>
void printArray(const std::vector<T>& a) {
    for (int ii = 0; ii < (int)a.size(); ii++) {
        std::cout << a[ii] << " ";
    }
    std::cout << std::endl;
}

// Java used java.util.Random; here we wrap <random> in a tiny helper that
// returns an int in [0, bound), like Java's rand.nextInt(bound). It is seeded
// once (nondeterministically) like Java's `new Random()`, so values differ
// each run.
int randomInt(int bound) {
    static std::mt19937 generator(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, bound - 1);
    return dist(generator);
}

std::vector<int> generateRandomArray(int len) {
    std::vector<int> a(len);
    for (int ii = 0; ii < (int)a.size(); ii++) {
        a[ii] = randomInt(1000);
    }
    return a;
}

// Java printed a List<...> as "[a, b, c]" (or "[]" when empty, "null" if null).
// Our Project-7 stubs return EMPTY vectors instead of Java's null, so this
// prints "[]". (In Java this line would have printed "null" because the stub
// returned null.)
template <typename T>
std::string listToString(const std::vector<T>& list) {
    std::ostringstream out;
    out << "[";
    for (int ii = 0; ii < (int)list.size(); ii++) {
        if (ii > 0) out << ", ";
        out << list[ii];
    }
    out << "]";
    return out.str();
}

template <typename T>
void testSortedArray(const std::vector<T>& a) {
    if (Sorting::isSorted(a)) {
        std::cout << "The array is sorted!" << std::endl;
    } else {
        std::cout << "The array is NOT sorted!" << std::endl;
    }
}

int main() {
    std::vector<int> a = generateRandomArray(LENGTH);

    // Test sort()
    std::cout << "Testing sort():" << std::endl;
    std::cout << "    Before sorting: ";
    printArray(a);
    Sorting::sort(a);   // Project-7 stub: does nothing
    std::cout << "    After sorting: ";
    printArray(a);
    testSortedArray(a);
    std::cout << std::endl;

    // test cutoff_qsort
    std::cout << "Testing cutoff_sort():" << std::endl;
    std::vector<int> sortup = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    std::vector<int> sortdown = {11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    std::cout << "    Before sorting: ";
    printArray(sortup);
    Sorting::cutoffQsort(sortup);   // Project-7 stub: does nothing
    std::cout << "    After sorting: ";
    printArray(sortup);
    testSortedArray(sortup);

    std::cout << "    Before sorting: ";
    printArray(sortdown);
    Sorting::cutoffQsort(sortdown);   // Project-7 stub: does nothing
    std::cout << "    After sorting: ";
    printArray(sortdown);
    testSortedArray(sortdown);

    for (int ii = 0; ii < 5; ii++) {
        a = generateRandomArray(LENGTH);
        std::cout << "    Before sorting: ";
        printArray(a);
        Sorting::cutoffQsort(a);   // Project-7 stub: does nothing
        std::cout << "    After sorting: ";
        printArray(a);
        testSortedArray(a);
    }
    std::cout << std::endl;

    std::vector<int> m1 = {10, 5, 15, 4, 14, 3, 13, 2, 12};
    std::vector<int> m2 = {5, 15, 4, 14, 3, 13, 2, 12, 10};
    std::vector<int> m3 = {2, 4, 6, 8, 10, 12, 14, 16, 18};
    std::vector<int> m4 = {20, 15, 10, 1};
    std::vector<int> m5 = {1, 2, 3, 3, 2, 1};

    // closest pair()
    // Note: closestPair is a Project-7 stub. Java returned null and printed
    // "null"; our C++ stub returns an empty vector, so this prints "[]".
    std::cout << "\nTesting closestPair()" << std::endl;
    a = generateRandomArray(LENGTH);
    std::cout << "    Closest pair a = " << listToString(Sorting::closestPair(a)) << std::endl;
    std::cout << "    Closest pair m1 = " << listToString(Sorting::closestPair(m1)) << std::endl;
    std::cout << "    Closest pair m2 = " << listToString(Sorting::closestPair(m2)) << std::endl;
    std::cout << "    Closest pair m3 = " << listToString(Sorting::closestPair(m3)) << std::endl;
    std::cout << "    Closest pair m4 = " << listToString(Sorting::closestPair(m4)) << std::endl;
    std::cout << "    Closest pair m5 = " << listToString(Sorting::closestPair(m5)) << std::endl;

    // firstN()
    // Note: firstN is also a Project-7 stub. Java returned null and printed
    // "null"; our C++ stub returns an empty vector, so this prints "[]".
    std::cout << "\nTesting firstN()" << std::endl;
    for (int ii = 0; ii < 3; ii++) {
        a = generateRandomArray(LENGTH);
        std::cout << "    First 2 of random array " << (ii + 1) << ": "
                  << listToString(Sorting::firstN(a, 2)) << std::endl;
        std::cout << "    First " << 3 * (ii + 1) << " of random array " << (ii + 1) << ": "
                  << listToString(Sorting::firstN(a, 3 * (ii + 1))) << std::endl;
    }
    std::vector<int> ntest1 = {3, 9, 6, 4, 1, 8, 2, 7, 5};
    std::vector<int> ntest2 = {1, 2, 1, 2, 1, 2, 1, 2};
    std::cout << "    First 2 of test1: " << listToString(Sorting::firstN(ntest1, 2)) << std::endl;
    std::cout << "    First 6 of test1: " << listToString(Sorting::firstN(ntest1, 6)) << std::endl;
    std::cout << "    First 2 of test2: " << listToString(Sorting::firstN(ntest2, 2)) << std::endl;
    std::cout << "    First 6 of test2: " << listToString(Sorting::firstN(ntest2, 6)) << std::endl;

    std::cout << "\nTesting shuffle():" << std::endl;
    Deck d(52);
    std::cout << "       Before shuffle: ";
    std::cout << d.toString() << std::endl;
    d.shuffle();   // Project-7 stub: does nothing, so the order is unchanged
    std::cout << "    After 1st shuffle: ";
    std::cout << d.toString() << std::endl;
    d.shuffle();   // Project-7 stub: does nothing, so the order is unchanged
    std::cout << "    After 2nd shuffle: ";
    std::cout << d.toString() << std::endl;

    return 0;
}
