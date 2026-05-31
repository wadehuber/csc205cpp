// MazeTester.cpp
//
// Driver: uses recursion to determine if a maze can be traversed.  Creates a
// new maze, prints its original form, attempts to solve it, and prints the
// final form.
//
// NOTE on file location: the Java version hard-coded a source-tree path prefix
// (filePath) and concatenated the entered filename onto it.  In this C++
// project the data files (testfile.txt, etc.) live in the same folder as the
// program, so we simply open the entered filename directly.  Run the program
// from this directory and enter e.g. "testfile.txt".

#include "Maze.h"
#include "MazeSolver.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "Enter the name of the file containing the maze: ";
    std::string filename;
    std::getline(std::cin, filename);

    // This assumes the text file is in the current directory.
    Maze labyrinth(filename);

    std::cout << labyrinth.toString() << std::endl;

    MazeSolver solver(labyrinth);

    if (solver.traverse(0, 0))
        std::cout << "The maze was successfully traversed!" << std::endl;
    else
        std::cout << "There is no possible path." << std::endl;

    std::cout << labyrinth.toString() << std::endl;

    return 0;
}
