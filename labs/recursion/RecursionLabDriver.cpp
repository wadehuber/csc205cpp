#include <iostream>
#include <vector>
#include "RecursionLab.h"

int main() {
    // Java used Arrays.asList(...); C++ uses a std::vector.
    std::vector<int> testValues = {1, 5, 10, 20};

    std::cout << "Recursion Lab Tests:" << std::endl;

    std::cout << "func1:" << std::endl;
    for (int ii : testValues) {
        std::cout << "[" << ii << "]: " << RecursionLab::func1(ii) << "   ";
    }
    std::cout << "\n" << std::endl;

    std::cout << "func2:" << std::endl;
    for (int jj = 0; jj < 3; jj++) {
        int ii = testValues[jj];
        std::cout << "[" << ii << "]: " << RecursionLab::func2(ii) << "   ";
    }
    std::cout << "\n" << std::endl;

    std::cout << "func3:" << std::endl;
    for (int ii : testValues) {
        std::cout << "[" << ii << "]: " << RecursionLab::func3(ii) << "   ";
    }
    std::cout << "\n" << std::endl;

    std::cout << "Tribonacci:" << std::endl;
    for (int ii : testValues) {
        std::cout << "[" << ii << "]: " << RecursionLab::tribonacci(ii) << "   ";
    }
    std::cout << "\n" << std::endl;

    std::cout << "add(x,y) testing:" << std::endl;
    std::cout << "[1 + 1] = " << RecursionLab::add(1, 1) << std::endl;
    std::cout << "[3 + 2] = " << RecursionLab::add(3, 2) << std::endl;
    std::cout << "[7 + 8] = " << RecursionLab::add(7, 8) << std::endl;
    std::cout << "" << std::endl;

    std::cout << "printDownFrom:" << std::endl;
    for (int ii : testValues) {
        std::cout << "[" << ii << "]: ";
        RecursionLab::printDownFrom(ii);
        std::cout << std::endl;
    }
    std::cout << "" << std::endl;

    std::cout << "printUpTo:" << std::endl;
    for (int ii : testValues) {
        std::cout << "[" << ii << "]: ";
        RecursionLab::printUpTo(ii);
        std::cout << std::endl;
    }
    std::cout << "" << std::endl;

    // Test Euclid's GCD algorithm
    std::cout << "GCD:" << std::endl;
    std::cout << "[96 & 60] " << RecursionLab::gcd(96, 60) << "    ";
    std::cout << "[30 & 10] " << RecursionLab::gcd(30, 10) << "    ";
    std::cout << "[96 & 120] " << RecursionLab::gcd(96, 120) << "    " << std::endl;
    std::cout << std::endl;

    // Test collatz()
    std::cout << "Collatz:" << std::endl;
    testValues = {1, 5, 19};
    for (int ii : testValues) {
        std::cout << "[" << ii << "] : ";
        RecursionLab::collatz(ii);
    }

    return 0;
}
