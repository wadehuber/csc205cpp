// Maze.cpp
//
// Implementation of the Maze class.

#include "Maze.h"
#include <fstream>
#include <stdexcept>

Maze::Maze(const std::string& filename) {
    // Java used a Scanner; here we use an ifstream and the >> operator, which
    // (like Scanner.nextInt) skips whitespace and reads one integer at a time.
    std::ifstream scan(filename);
    if (!scan) {
        throw std::runtime_error("File not found: " + filename);
    }

    scan >> numberRows;
    scan >> numberColumns;

    // Allocate a numberRows x numberColumns grid.
    grid.assign(numberRows, std::vector<int>(numberColumns));
    for (int i = 0; i < numberRows; i++)
        for (int j = 0; j < numberColumns; j++)
            scan >> grid[i][j];
    scan.close();

    endRow = getRows() - 1;
    endColumn = getColumns() - 1;
}

void Maze::tryPosition(int row, int col) {
    grid[row][col] = TRIED;
}

bool Maze::solved(int row, int col) {
    return (row == endRow && col == endColumn);
}

int Maze::getRows() {
    return (int)grid.size();
}

int Maze::getColumns() {
    return (int)grid[0].size();
}

void Maze::markPath(int row, int col) {
    grid[row][col] = PATH;
}

bool Maze::validPosition(int row, int column) {
    bool result = false;

    // check if cell is in the bounds of the matrix
    if (row >= 0 && row < (int)grid.size() &&
            column >= 0 && column < (int)grid[row].size())

        //  check if cell is open (not blocked and not previously tried)
        if (grid[row][column] == OPEN)
            result = true;

    return result;
}

std::string Maze::toString() const {
    std::string result = "\n";

    for (std::size_t row = 0; row < grid.size(); row++) {
        for (std::size_t column = 0; column < grid[row].size(); column++)
            result += std::to_string(grid[row][column]);
        result += "\n";
    }

    return result;
}
