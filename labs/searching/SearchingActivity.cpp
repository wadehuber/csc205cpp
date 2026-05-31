#include <iostream>
#include <string>
#include <vector>
#include <random>
#include "Searching.h"

// Small helper that wraps C++'s <random> to mimic Java's rand.nextInt(bound)
// (a value in [0, bound)). Seeded once. Like Java's "new Random()", this is
// seeded nondeterministically, so the non-uniform results differ run-to-run.
static int randomInt(int bound) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, bound - 1);
    return dist(gen);
}

// Helper to print a search result the way Java prints an Integer (the value,
// or "null" when not found / the pointer is nullptr).
static std::string resultText(const int* result) {
    if (result == nullptr) {
        return "null";
    }
    return std::to_string(*result);
}

int main() {
    const int* result;

    std::vector<int> a(5000);
    std::vector<int> b(5000);

    // Uniform distribution
    for (int ii = 0; ii < (int) a.size(); ii++) {
        a[ii] = ii * 2;
    }

    // Non-uniform distribution (note: like the Java original, the running
    // sum overflows a 32-bit int at large indices -- kept on purpose).
    b[0] = 1;
    for (int ii = 1; ii < (int) b.size(); ii++) {
        b[ii] = (b[ii - 1] + randomInt(20)) + ii * ii * 2;
    }

    int testValues[] = {-1, 1, 4, 41, 440, 8800, 9990, 1000000};

    std::cout << "UNIFORM DISTRIBUTION" << std::endl;
    std::cout << "Binary Search:" << std::endl;
    for (int x : testValues) {
        std::cout << "  Searching for (" << x << "): ";
        result = Searching::binarySearch(a, x);
        std::cout << " binary: " << resultText(result) << " in " << Searching::getCounter();
        result = Searching::interpolationSearch(a, x);
        std::cout << "\t\t interpolation: " << resultText(result) << " in " << Searching::getCounter() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "NON-UNIFORM DISTRIBUTION" << std::endl;
    for (int x : testValues) {
        std::cout << "  Searching for (" << x << "): ";
        result = Searching::binarySearch(b, x);
        std::cout << "\tbinary: " << resultText(result) << " in " << Searching::getCounter();
        result = Searching::interpolationSearch(b, x);
        std::cout << "\t\t interpolation: " << resultText(result) << " in " << Searching::getCounter() << std::endl;
    }

    return 0;
}
