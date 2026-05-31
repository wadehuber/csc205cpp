// TowersOfHanoi.cpp
//
// Implementation of the Towers of Hanoi puzzle.

#include "TowersOfHanoi.h"
#include <iostream>

TowersOfHanoi::TowersOfHanoi(int disks) {
    totalDisks = disks;
}

void TowersOfHanoi::solve() {
    moveTower(totalDisks, "A", "C", "B");
}

void TowersOfHanoi::moveTower(int numDisks, const std::string& start,
                              const std::string& end, const std::string& temp) {
    if (numDisks == 1)
        std::cout << "Move top disk from peg " << start << " to peg " << end << "." << std::endl;
    else {
        moveTower(numDisks - 1, start, temp, end);
        std::cout << "Move top disk from peg " << start << " to peg " << end << "." << std::endl;
        moveTower(numDisks - 1, temp, end, start);
    }
}
