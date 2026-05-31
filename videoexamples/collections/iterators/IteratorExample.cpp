// IteratorExample.cpp
// C++ version of IteratorExample.java.
//
// Uses the EvenNumbers iterator with its Java-style hasNext()/next() methods.

#include <iostream>
#include "EvenNumbers.h"

int main() {
    EvenNumbers evens(10);
    EvenNumbers moreEvens;

    std::cout << "evens (iterator): ";
    while (evens.hasNext()) {
        std::cout << evens.next() << " ";
    }
    std::cout << std::endl;

    std::cout << "moreEvens (iterator): ";
    for (int ii = 0; ii < 20; ii++) {
        std::cout << moreEvens.next() << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "5 moreEvens (iterator): ";
    for (int ii = 0; ii < 5; ii++) {
        std::cout << moreEvens.next() << " ";
    }
    std::cout << std::endl;

    std::cout << "20 moreEvens (iterator): ";
    for (int ii = 0; ii < 20; ii++) {
        std::cout << moreEvens.next() << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // Make a fresh iterator (Java reassigned moreEvens to a new EvenNumbers).
    moreEvens = EvenNumbers();
    std::cout << "Resetting moreEvens" << std::endl;
    for (int ii = 0; ii < 20; ii++) {
        std::cout << moreEvens.next() << " ";
    }
    std::cout << std::endl;

    return 0;
}
