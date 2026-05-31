// MazeSolver.cpp
//
// Implementation of the recursive maze solver.  The recursion structure is
// identical to the Java version.

#include "MazeSolver.h"

MazeSolver::MazeSolver(Maze& maze) : maze(maze) {
}

bool MazeSolver::traverse(int row, int column) {
    bool done = false;

    if (maze.validPosition(row, column)) {
        maze.tryPosition(row, column);   // mark this cell as tried

        if (maze.solved(row, column)) {
            done = true;  // the maze is solved
        }
        else {
            if (!done)
                done = traverse(row - 1, column);  // up
            if (!done)
                done = traverse(row, column - 1);  // left
            if (!done)
                done = traverse(row + 1, column);  // down
            if (!done)
                done = traverse(row, column + 1);  // right
        }

        if (done)  // this location is part of the final path
            maze.markPath(row, column);
    }

    return done;
}
