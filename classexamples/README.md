# csc205codeexamples - Class Examples (C++ version)

This directory contains the C++ versions of the code examples done during
class. They are translated from the Java originals in
[`../../../java/src/classexamples`](../../../java/src/classexamples), and are
written to stay as close to the Java as possible while using simple C++.

## Modules

- **module02** — abstract classes & inheritance (`Thing` → `Something` / `SomethingElse`)
- **module03** — polymorphism through an abstract base class (`Animal` → `Dog` / `Bear`) and through an interface (`Fights`, `Boxer`)
- **module04** — writing to a file (`std::ofstream`)
- **module05** — recursion
- **module06** — collections, a generic class (`MyCollection<T>`), and a custom iterator

## How to build and run

You need a C++ compiler (`g++`) and `make`. On Windows the easiest option is
[MinGW-w64](https://www.mingw-w64.org/) (which provides `g++` and
`mingw32-make`).

Each module has its own `Makefile`. From inside a module's folder:

```
make        # compile the program
make run    # compile (if needed) and run it
make clean  # delete the compiled program
```

On Windows with MinGW, use `mingw32-make` in place of `make`.

If you don't want to use `make`, you can compile by hand, e.g. for module02:

```
g++ -std=c++17 -Wall -o inheritance InheritanceExample.cpp Thing.cpp Something.cpp SomethingElse.cpp
```

## Notes on the Java → C++ translation

- Each Java class becomes a header file (`.h`, the declarations) plus a source
  file (`.cpp`, the code). Template (generic) classes are the exception: they
  live entirely in a `.h` file.
- Java's `extends` and `implements` both become `: public Base` in C++. An
  `interface` becomes a class made only of pure virtual functions (`= 0`).
- Java reaches objects through references and a garbage collector. C++ uses
  objects on the stack; when we need an "array of different subtypes", we use a
  `std::vector` of pointers to those stack objects (no `new`/`delete` needed).
- Java's `toString()` is provided as a `toString()` method that returns a
  `std::string`; we print it with `std::cout << x.toString()`.
