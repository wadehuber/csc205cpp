#include <iostream>
#include <vector>
#include <random>
#include "searching.hpp"

int main() {
    std::optional<int> result;
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> dist(0, 19);

    std::vector<int> a(5000);
    std::vector<int> b(5000);

    // Uniform distribution
    for (int i = 0; i < a.size(); ++i) {
        a[i] = i * 2;
    }

    // Non-uniform distribution
    b[0] = 1;
    for (int i = 1; i < b.size(); ++i) {
        b[i] = b[i - 1] + dist(rng) + i * i * 2;
    }

    std::vector<int> testValues = {-1, 1, 4, 41, 440, 8800, 9990, 1000000};

    std::cout << "UNIFORM DISTRIBUTION\n";
    std::cout << "Binary Search:\n";
    for (int x : testValues) {
        std::cout << "  Searching for (" << x << "): ";
        result = Searching::binarySearch(a, x);
        std::cout << " binary: ";
        if (result) std::cout << *result;
        else std::cout << "null";
        std::cout << " in " << Searching::getCounter();

        result = Searching::interpolationSearch(a, x);
        std::cout << "\t\t interpolation: ";
        if (result) std::cout << *result;
        else std::cout << "null";
        std::cout << " in " << Searching::getCounter() << "\n";
    }

    std::cout << "\nNON-UNIFORM DISTRIBUTION\n";
    for (int x : testValues) {
        std::cout << "  Searching for (" << x << "): ";
        result = Searching::binarySearch(b, x);
        std::cout << "\tbinary: ";
        if (result) std::cout << *result;
        else std::cout << "null";
        std::cout << " in " << Searching::getCounter();

        result = Searching::interpolationSearch(b, x);
        std::cout << "\t\t interpolation: ";
        if (result) std::cout << *result;
        else std::cout << "null";
        std::cout << " in " << Searching::getCounter() << "\n";
    }

    return 0;
}
