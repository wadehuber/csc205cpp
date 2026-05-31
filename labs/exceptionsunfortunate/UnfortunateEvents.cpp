#include "UnfortunateEvents.h"
#include <iostream>

void UnfortunateEvents::bottlesOfBeer() {
    // std::cin is C++'s console input (like Java's Scanner on System.in).
    std::cout << "How many bottles of beer to start with?  ";
    int count;
    std::cin >> count;
    countThemDown(count);
}

void UnfortunateEvents::countThemDown(int n) {
    // We will count down to 0
    if (n != 0) {
        // Obviously, you can't have negative bottles of beer on the wall!
        if (n > 0) {
            std::cout << n << " bottles of beer on the wall" << std::endl;
        }

        // This next line is recursion, which we haven't covered yet, but
        //   that doesn't matter for this assignment
        countThemDown(n - 1);
    }
}
