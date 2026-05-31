// Algorithms.cpp
//
// Compares two algorithms for finding the max element in an array, both for
// the number of comparisons they make and their running time.
//
// Java version used System.nanoTime() and printf().  Here we use
// <chrono> for the high-resolution clock and std::printf for formatted output.
//
// In Java this was a class with static methods + main.  In C++ that becomes
// a file of free functions + main (no class needed for a bundle of statics).

#include <cstdio>
#include <vector>
#include <random>
#include <chrono>

// Java passed "Integer arr[]"; in C++ we use std::vector<int>.
// We pass by reference (std::vector<int>&) so the array is not copied -
// this matches Java, where arrays are passed by reference.
void fillRandomArray(std::vector<int>& arr) {
    // A single random engine, seeded once.  static so we keep one generator
    // across calls (similar to reusing a single java.util.Random).
    static std::mt19937 rand(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 9999);  // nextInt(10000): 0..9999

    auto start = std::chrono::high_resolution_clock::now();
    for (std::size_t ii = 0; ii < arr.size(); ii++) {
        arr[ii] = dist(rand);
    }
    auto end = std::chrono::high_resolution_clock::now();
    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::printf("Filled array of length %7zu in %lld\n", arr.size(), ns);
}

void findMaxSlow(const std::vector<int>& arr) {
    bool thisIsMax = false;
    int max = 0;
    long long counter = 0;

    auto start = std::chrono::high_resolution_clock::now();
    for (std::size_t current = 0; current < arr.size(); current++) {
        thisIsMax = true;
        for (std::size_t ii = 0; ii < arr.size(); ii++) {
            counter++;
            if (arr[current] < arr[ii]) {
                thisIsMax = false;
            }
        }
        if (thisIsMax) {
            max = arr[current];
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::printf("%10zu%10d%15lld%12lld\n", arr.size(), max, counter, ns);
}

void findMaxFast(const std::vector<int>& arr) {
    int max;
    long long counter = 0;

    auto start = std::chrono::high_resolution_clock::now();
    max = arr[0];
    for (std::size_t ii = 0; ii < arr.size(); ii++) {
        counter++;
        if (arr[ii] > max) {
            max = arr[ii];
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    long long ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
    std::printf("%10zu%10d%15lld%12lld\n", arr.size(), max, counter, ns);
}

int main() {
    std::vector<int> numbers10(10);
    std::vector<int> numbers100(100);
    std::vector<int> numbers1000(1000);
    std::vector<int> numbers10000(10000);
    std::vector<int> numbers100000(100000);

    fillRandomArray(numbers10);
    fillRandomArray(numbers100);
    fillRandomArray(numbers1000);
    fillRandomArray(numbers10000);
    fillRandomArray(numbers100000);

    std::printf("\n");
    std::printf("Finding max (slow method):\n");
    std::printf("%10s%10s%15s%12s\n", "Length", "Max", "Comparisons", "Time");
    findMaxSlow(numbers10);
    findMaxSlow(numbers100);
    findMaxSlow(numbers1000);
    findMaxSlow(numbers10000);
    findMaxSlow(numbers100000);

    std::printf("\n");
    std::printf("Finding max (fast method):\n");
    std::printf("%10s%10s%15s%12s\n", "Length", "Max", "Comparisons", "Time");
    findMaxFast(numbers10);
    findMaxFast(numbers100);
    findMaxFast(numbers1000);
    findMaxFast(numbers10000);
    findMaxFast(numbers100000);

    return 0;
}
