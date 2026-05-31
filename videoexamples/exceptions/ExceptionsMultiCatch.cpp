#include <iostream>
#include <vector>
#include <stdexcept>

// Example of catching several different exception types.
// In Java this was ExceptionsMultiCatch.
//
// In Java, numbers[10] on a 6-element array throws
// ArrayIndexOutOfBoundsException automatically. In C++, indexing a plain
// array or vector out of bounds is undefined behavior and does NOT throw.
// But std::vector::at(i) DOES throw std::out_of_range, so we use that to
// get Java-like behavior.
int main() {
    try {
        std::vector<int> numbers = {1, 2, 3, 4, 5, 6};
        std::cout << numbers.at(10) << std::endl;   // Issue #1: out of range (throws)
        // Issue #2 in Java was "10 / 0" (ArithmeticException). In C++ that
        // would just crash, and the at(10) above already threw, so this is
        // unreachable -- left as a comment to mirror the Java example.
        // int result = 10 / 0;
        // std::cout << result << std::endl;
    }
    // Java caught ArrayIndexOutOfBoundsException; the C++ equivalent thrown
    // by vector::at is std::out_of_range.
    catch (const std::out_of_range& e) {
        std::cout << "Array index problem: " << e.what() << std::endl;
    }
    // C++ has no ArithmeticException for "/ by zero". We keep a catch clause
    // for any other standard exception, mirroring Java's structure.
    catch (const std::exception& e) {
        std::cout << "Something else went wrong: " << e.what() << std::endl;
    }

    return 0;
}
