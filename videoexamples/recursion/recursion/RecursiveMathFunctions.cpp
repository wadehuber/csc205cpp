// RecursiveMathFunctions.cpp
//
// Four example recursive functions showing multiple base cases, multiple
// recursive cases, and a case where the recursive call adds one to the
// parameter (counting UP).

#include <iostream>

// Recursive mathematical formula
//   f(1) = 1
//   f(n) = 2n^2 + n - f(n-1)
int recursiveFunction(int n) {
    if (n <= 1) {
        return 1;
    }
    else {
        return ((2 * n * n) + n - recursiveFunction(n - 1));
    }
}

// Recursive mathematical formula with multiple base cases
// f(1) = 0                            // Base case
// f(3) = 1                            // Base case
// f(n) = n (if n is a multiple of 5)  // Base case
// f(n) = n + f(n-1) (otherwise)       // Recursive case
int multipleBaseCases(int n) {
    if (n <= 1) {
        return 0;
    }
    else if (n == 3) {
        return 1;
    }
    else if ((n % 5) == 0) {
        return n;
    }
    else {
        return (n + multipleBaseCases(n - 1));
    }
}

// Recursive mathematical formula with multiple recursive cases
// f(1) = 1
// f(n) = n/2 + f(n-1) (if n is even)
// f(n) = n-1 + f(n-1) (if n is odd)
int multipleRecursiveCases(int n) {
    if (n <= 1) {
        return 1;
    }
    else if ((n % 2) == 0) { // n is even
        return ((n / 2) + multipleRecursiveCases(n - 1));
    }
    else { // n is odd
        return ((n - 1) + multipleRecursiveCases(n - 1));
    }
}

// Recursive mathematical formula where we count UP
// f(n) = n + f(n+2)   (if n < 100)
// f(n) = 100          (if n >= 100)
int recursiveCountUp(int n) {
    if (n >= 100) {
        return 100;
    }
    else {
        return (n + recursiveCountUp(n + 2));
    }
}

int main() {
    std::cout << "recursiveFunction:" << std::endl;
    for (int ii = 1; ii <= 10; ii++) {
        std::cout << "  f(" << ii << ") = " << recursiveFunction(ii) << std::endl;
    }
    std::cout << std::endl;

    std::cout << "multipleBaseCases:" << std::endl;
    for (int ii = 1; ii <= 10; ii++) {
        std::cout << "  f(" << ii << ") = " << multipleBaseCases(ii) << std::endl;
    }
    std::cout << std::endl;

    std::cout << "multipleRecursiveCases:" << std::endl;
    for (int ii = 1; ii <= 10; ii++) {
        std::cout << "  f(" << ii << ") = " << multipleRecursiveCases(ii) << std::endl;
    }
    std::cout << std::endl;

    std::cout << "recursiveCountUp:" << std::endl;
    for (int ii = 1; ii <= 10; ii++) {
        std::cout << "  f(" << ii << ") = " << recursiveCountUp(ii) << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
