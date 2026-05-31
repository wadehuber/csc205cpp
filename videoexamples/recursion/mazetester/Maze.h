// Maze.h
//
// Maze represents a maze of characters.  The goal is to get from the top left
// corner to the bottom right, following a path of 1's.  Arbitrary constants
// are used to represent locations that have been TRIED and that are part of
// the solution PATH.
//
// Java class -> C++ .h (declaration) + .cpp (definition).

#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <vector>

class Maze {
private:
    static const int OPEN = 1;
    static const int TRIED = 2;
    static const int PATH = 3;

    int numberRows, numberColumns;
    int endRow, endColumn;            // Coordinates of end point of maze
    // Java int[][] grid -> C++ vector of vectors of int.
    std::vector<std::vector<int>> grid;

public:
    // Constructor: loads a maze from the given file.  In Java this threw a
    // FileNotFoundException; here we throw std::runtime_error if the file
    // cannot be opened.
    Maze(const std::string& filename);

    // Marks the specified position in the maze as TRIED.
    void tryPosition(int row, int col);

    // Check if a position is the end of the maze.
    bool solved(int row, int col);

    // Return the number of rows in this maze.
    int getRows();

    // Return the number of columns in this maze.
    int getColumns();

    // Marks a given position in the maze as part of the PATH.
    void markPath(int row, int col);

    // Determines if a specific location is valid.  A valid location is one
    // that is on the grid, is not blocked, and has not been TRIED.
    bool validPosition(int row, int column);

    // Returns the maze as a string.
    // (Java's toString(); print via std::cout << maze.toString().)
    std::string toString() const;
};

#endif
