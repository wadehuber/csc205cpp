#include <iostream>
#include <stdexcept>
#include "YouDidTheWrongThingException.h"

// Example of throwing and catching our own custom exception.
// In Java this was CreatingExceptions.
//
// Java read the number with scan.nextInt(), which throws
// InputMismatchException on bad input. In C++, "std::cin >> num" does not
// throw; it sets cin to a fail state. We check !(std::cin >> num) and throw
// std::runtime_error to mimic Java's InputMismatchException catch clause.
int main() {
    int num;

    try {
        std::cout << "Enter a number:  ";
        if (!(std::cin >> num)) {
            throw std::runtime_error("Invalid input type.");
        }

        // throw by VALUE in C++ (Java was "throw new ...").
        if (num == 13) {
            throw YouDidTheWrongThingException("UNLUCKY NUMBER!");
        }

        std::cout << "Numbers up to " << num << ":" << std::endl;
        for (int ii = 0; ii < num; ii++) {
            std::cout << ii << " ";
        }
        std::cout << std::endl;
    }
    // Our most-specific custom type first...
    catch (const YouDidTheWrongThingException& e) {
        std::cerr << e.what() << std::endl;
    }
    // ...then the "bad input" case (Java caught InputMismatchException).
    catch (const std::exception& e) {
        std::cerr << "Invalid input type." << std::endl;
    }

    return 0;
}
