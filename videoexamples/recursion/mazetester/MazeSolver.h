// MazeSolver.h
//
// MazeSolver attempts to recursively traverse a Maze.  The goal is to get from
// the given starting position to the bottom right, following a path of 1's.
//
// Java class -> C++ .h (declaration) + .cpp (definition).

#ifndef MAZESOLVER_H
#define MAZESOLVER_H

#include "Maze.h"

class MazeSolver {
private:
    // The Java field "private Maze maze;" held a reference to the shared Maze.
    // We use a reference here so the solver marks the *same* Maze object the
    // driver created (rather than a copy).
    Maze& maze;

public:
    MazeSolver(Maze& maze);

    // Attempts to recursively traverse the maze, marking TRIED cells and the
    // final PATH.  Returns true if the maze has been solved.
    bool traverse(int row, int column);
};

#endif
