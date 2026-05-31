# csc205codeexamples - Exercise Starter Code (C++ version)

This directory contains the C++ versions of the CSC205 exercise starter code,
translated from the Java originals in
[`../../../java/src/exercises`](../../../java/src/exercises). See the links in
your Canvas course to ensure you are using the right starter code for your
class.

As with the Java starters, some of this code is intentionally incomplete --
the exercise is for you to finish it. For example, the `comparable` exercise
asks you to add a way to compare two `Date` objects (Java's `Comparable`
interface / `compareTo` method; in C++, a `compareTo` method and/or
`operator<`).

Each exercise folder has its own `Makefile`:

```
make        # compile the program
make run    # compile (if needed) and run it
make clean  # delete the compiled program
```

On Windows with MinGW, use `mingw32-make` instead of `make`.
