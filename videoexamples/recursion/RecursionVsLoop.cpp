// RecursionVsLoop.cpp
//
// Shows the same "add up the numbers 0..n" computed both recursively and with
// a loop.  Recursion maps 1-to-1 from Java to C++.

#include <iostream>

int addUpRecursive(int n) {
    if (n <= 0) {
        return 0;
    }
    else {
        return n + addUpRecursive(n - 1);
    }
}

int addUpLoop(int n) {
    int sum = 0;
    for (int ii = 0; ii <= n; ii++) {
        sum += ii;
    }
    return sum;
}

int main() {
    for (int ii = 0; ii < 10; ii++) {
        std::cout << "ii=" << ii << std::endl;
        std::cout << "  Recursion: " << addUpRecursive(ii) << std::endl;
        std::cout << "       Loop: " << addUpLoop(ii) << std::endl;
    }
    return 0;
}
