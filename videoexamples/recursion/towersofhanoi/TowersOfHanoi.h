// TowersOfHanoi.h
//
// TowersOfHanoi represents the classic Towers of Hanoi puzzle.
//
// Java class -> C++ .h (declaration) + .cpp (definition).

#ifndef TOWERSOFHANOI_H
#define TOWERSOFHANOI_H

#include <string>

class TowersOfHanoi {
private:
    int totalDisks;

    // Moves the specified number of disks from one tower to another by moving
    // a subtower of n-1 disks out of the way, moving one disk, then moving the
    // subtower back.  Base case of 1 disk.
    void moveTower(int numDisks, const std::string& start,
                   const std::string& end, const std::string& temp);

public:
    // Sets up the puzzle with the specified number of disks.
    TowersOfHanoi(int disks);

    // Performs the initial call to moveTower to solve the puzzle.
    void solve();
};

#endif
