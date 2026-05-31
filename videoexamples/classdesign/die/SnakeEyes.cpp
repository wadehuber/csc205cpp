//********************************************************************
//  SnakeEyes.cpp
//
//  C++ version of SnakeEyes.java.
//  Demonstrates the use of a programmer-defined class (Die).
//  Creates two Die objects and rolls them several times, counting
//  the number of "snake eyes" (both dice showing 1) that occur.
//********************************************************************
#include <iostream>

#include "Die.h"

int main() {
    const int ROLLS = 720;
    int count = 0;

    Die die1(6);
    Die die2(6);

    for (int roll = 1; roll <= ROLLS; roll++) {
        die1.roll();
        die2.roll();

        // Java printed "die1 + " " + die2", which used Die.toString().
        // In C++ we call toString() explicitly.
        std::cout << die1.toString() << " " << die2.toString() << std::endl;

        if (die1.getFaceValue() == 1 && die2.getFaceValue() == 1) {
            count++;
        }
    }

    std::cout << "\nNumber of rolls: " << ROLLS << std::endl;
    std::cout << "Number of snake eyes: " << count << std::endl;
    // Java cast count to float before dividing; we cast to double so the
    // division is floating-point rather than integer.
    std::cout << "Ratio: " << (double)count / ROLLS << std::endl;

    return 0;
}
