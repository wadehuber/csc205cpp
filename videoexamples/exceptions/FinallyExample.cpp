#include <iostream>
#include <stdexcept>

// Example of "finally"-style cleanup that runs no matter what.
// In Java this was FinallyExample.
//
// Two big differences from Java:
//  1. C++ has no "finally" block. We put the cleanup AFTER the try/catch.
//     But Java's finally also ran when the method RETURNED early from the
//     catch -- so on that path we repeat the cleanup line before returning.
//  2. "std::cin >> num" does NOT throw on bad input (Java's nextInt() threw
//     InputMismatchException). Instead cin goes into a "fail" state, which
//     we detect with !(std::cin >> num) and throw ourselves to mimic Java.

int checkThisOut() {
    int num = 0;

    try {
        std::cout << "Enter a number : ";
        if (!(std::cin >> num)) {
            // bad / non-numeric input -- mimic Java's InputMismatchException
            throw std::runtime_error("InputMismatch");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "You did not enter a valid input!" << std::endl;
        // "finally" cleanup must also run on this early-return path:
        std::cout << "Your result is going to be " << num << std::endl;
        return -1;
    }

    // The "finally" cleanup on the normal path (after the try/catch):
    std::cout << "Your result is going to be " << num << std::endl;

    return num;
}

int main() {
    int num;

    num = checkThisOut();

    std::cout << "The result is " << num << std::endl;

    return 0;
}
