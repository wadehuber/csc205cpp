# Recursion & Analysis of Algorithms (C++ version)

These are C++ conversions of the CSC205 Java teaching examples. The goal was to
stay as close to the Java as possible (same names, output, and program flow)
while using simple, idiomatic C++. Where a technique differs from Java there is
a short comment in the source explaining the difference.

Each folder has its own `Makefile`:

```
make        # build
make run    # build and run
make clean  # delete the built program(s)
```

Build settings are `g++ -std=c++17 -Wall`. On Windows with MinGW-w64 use
`mingw32-make`.

## Algorithms

- `Algorithms.cpp` shows a comparison of two algorithms for finding the max
  element in an array, compared both for the number of comparisons they make
  and their running time. Java used `System.nanoTime()` and `printf()`; the C++
  version uses `<chrono>` for timing and `std::printf` for formatted output.
- `AnalyzeLoops.cpp` first demonstrates how to analyze methods with loops, then
  gives example methods with a variety of asymptotic complexity.

These two programs are independent (each has its own `main`) and share the
top-level `Makefile`.

## Recursion

The recursive examples live in the nested `recursion/` folder (the same nesting
as the Java `recursion/recursion/`):

### RecursionExamples.cpp
Examples of simple recursive functions. Most of these problems can be solved
more efficiently without recursion; they exist to help you start seeing
recursive solutions.

- Summing the numbers up to N (iteration & recursion)
- Factorial
- Printing the numbers up to N
- Tail-recursive versions of sum and factorial (using overloaded helper
  functions, just like the overloaded Java methods)

### RecursiveMathFunctions.cpp
Four example functions with multiple base cases, multiple recursive cases, and
a case where the recursive call adds one to the parameter (counting up).

### RecursionWithStrings.cpp
Recursion with strings:

- Recursively reversing a string
- Recursively checking if a string contains a specific character
- Drawing a square using recursion

Java `String` maps to `std::string`: `charAt(i)` -> `s[i]`,
`substring(1)` -> `s.substr(1)`, `length()` -> `.length()`.

### RecursionWithArrays.cpp
Using helper functions to recursively work with arrays without changing them:

- Recursively summing the elements in an array
- Checking the "fold balance" of an array (recursion that moves inward from
  both ends)

Java arrays (`Integer[]`) map to `std::vector<int>`, passed by const reference
so they are not copied.

There is also a top-level `RecursionVsLoop.cpp` and `RecursiveDefinition.cpp`
demonstrating a recursive function next to its loop equivalent and a simple
recursive definition.

### towersofhanoi
Recursive Towers of Hanoi solver.

- `TowersOfHanoi.h` / `TowersOfHanoi.cpp` - class that represents the puzzle
- `SolveTowers.cpp` - driver with `main`

The driver and the helper class compile together (see the Makefile).

### mazetester
Recursive maze solver.

- `Maze.h` / `Maze.cpp` - represents a maze in a 2D grid (`vector<vector<int>>`)
- `MazeSolver.h` / `MazeSolver.cpp` - finds a path (or reports none) via
  recursive backtracking; the recursion structure is identical to the Java
- `MazeTester.cpp` - driver with `main`
- `testfile.txt`, `testfile2.txt`, `testfile3.txt` - sample mazes

The maze is loaded with `std::ifstream` and the `>>` operator, which reads one
integer at a time and skips whitespace (the same behaviour as Java's
`Scanner.nextInt()`).

Run it, then type a maze filename when prompted:

```
make run
Enter the name of the file containing the maze: testfile.txt
```

**Difference from Java:** the Java `MazeTester` hard-coded a source-tree path
prefix and appended the filename you typed. In this C++ project the data files
sit in the same folder as the program, so the C++ driver opens the entered
filename directly. Run the program from the `mazetester` directory so it can
find the `.txt` files.
