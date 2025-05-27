#ifndef UNFORTUNATE_EVENTS_H
#define UNFORTUNATE_EVENTS_H

#include <iostream>

class UnfortunateEvents {
public:
    // Public method: asks for input and begins countdown
    static void bottlesOfBeer() {
        int start;
        std::cout << "How many bottles of beer to start with?  ";
        std::cin >> start;
        countThemDown(start);
    }

private:
    // Private recursive helper method
    static void countThemDown(int n) {
        if (n != 0) {
            if (n > 0) {
                std::cout << n << " bottles of beer on the wall\n";
            }
            countThemDown(n - 1);
        }
    }
};

#endif
