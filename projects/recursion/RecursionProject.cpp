#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include "csc205/Recursion.h"

// Java had a static helper printArray(Integer[]); here it takes a
// std::vector<int>. It prints each element followed by a space.
void printArray(const std::vector<int>& a) {
    for (std::size_t ii = 0; ii < a.size(); ii++) {
        std::cout << a[ii] << " ";
    }
}

int main() {
    // Java used Arrays.asList(...); C++ uses a std::vector.
    std::vector<int> testValues = {1, 5, 10, 20};

    std::cout << "Project 4 Testing:" << std::endl;

    // Test Fibonacci
    std::cout << std::endl;
    std::cout << "Fibonacci:" << std::endl;
    std::cout << "  ";
    for (int ii : testValues) {
        std::cout << Recursion::fib(ii) << "   ";
    }
    std::cout << std::endl;

    // Test the Ackermann function
    std::cout << std::endl;
    std::cout << "Ackermann:" << std::endl;
    testValues = {1, 2, 3};
    for (int ii : testValues) {
        std::cout << "  ";
        for (int jj = 0; jj < 5; jj++) {
            std::cout << Recursion::ackermann(ii, jj) << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // Test balance function
    std::cout << "Balance:" << std::endl;
    std::cout << "  ";
    std::cout << "[10 20]: " << Recursion::balance(10, 20) << "    ";
    std::cout << "[20 10]: " << Recursion::balance(20, 10) << "    ";
    std::cout << "[10 21]: " << Recursion::balance(10, 21) << "    ";
    std::cout << std::endl;
    std::cout << "  ";
    std::cout << "[21 10]: " << Recursion::balance(21, 10) << "    ";
    std::cout << "[10 10]: " << Recursion::balance(10, 10) << "    ";
    std::cout << "[10 11]: " << Recursion::balance(10, 11) << "    ";
    std::cout << std::endl;

    // Test the Pi approximation function
    std::cout << std::endl;
    testValues = {5, 20, 50};
    std::cout << "Pi:" << std::endl;
    std::cout << "  ";
    for (int ii : testValues) {
        // Java: String.format("%.3f", ...). Here we use an ostringstream
        // with std::fixed and std::setprecision(3) to get the same format.
        std::ostringstream pi;
        pi << std::fixed << std::setprecision(3) << Recursion::pi_approximation(ii);
        std::cout << "[" << ii << "] : " << pi.str() << "     ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "isPalindrome:" << std::endl;
    std::vector<std::string> testStrings = {"a", "ab", "aa", "aba", "aabcbaa", "abcdba", "aabbccbbaa", "notapalindrome"};
    for (const std::string& str : testStrings) {
        if (Recursion::isPalindrome(str)) {
            std::cout << "  " << str << " is a palindrome." << std::endl;
        } else {
            std::cout << "  " << str << " is NOT a palindrome." << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "monotonicallyIncreasing:" << std::endl;
    // Java used Integer[][]; here a std::vector of std::vector<int>.
    std::vector<std::vector<int>> testArrays = {{1}, {1, 2, 3}, {3, 2, 1}, {1, 2, 3, 1}, {9, 8, 7}, {1, 2}, {2, 1}};
    for (const std::vector<int>& a : testArrays) {
        if (Recursion::monotonicallyIncreasing(a)) {
            std::cout << "  ";
            printArray(a);
            std::cout << " is monotonically increasing." << std::endl;
        } else {
            std::cout << "  ";
            printArray(a);
            std::cout << " is NOT monotonically increasing." << std::endl;
        }
    }

    return 0;
}
