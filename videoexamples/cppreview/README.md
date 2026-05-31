# C++ Review (cppreview)

This directory is the C++ version of the Java `javareview` examples. It is a
brief review of programming basics for CSC205 students -- but written in C++
instead of Java. Each example is annotated with comments pointing out where C++
differs from the Java you may already know.

The original Java videos still explain the concepts; these files show how the
same ideas look in idiomatic C++.

## Building and running

Each sub-directory has a `Makefile`:

```
make        # build the program(s) in that directory
make run    # build and run the non-interactive program(s)
make clean  # delete the built executables
```

The Makefiles use `g++ -std=c++17 -Wall`. On Windows with MinGW-w64, use
`mingw32-make`.

## cppreview/

- `ClassExample` (.h/.cpp): writing a class in C++ -- header declares, .cpp
  defines. Shows fields, overloaded/delegating constructors, and `toString()`.
- `Arrays.cpp`: C++ raw arrays vs `std::vector`. `std::vector` is the closest
  thing to a Java array/ArrayList and knows its own `.size()` (Java's `.length`).
- `Functions.cpp`: free functions; pass-by-value vs pass-by-reference (`int&`),
  and passing a `std::vector` by const reference.
- `ControlStructures.cpp`: if/else, switch, while, do-while, for, break,
  continue (nearly identical to Java); reads input with `std::cin`.
- `Wrapper.cpp`: C++ has NO wrapper classes and NO autoboxing -- an `int` is
  just an `int`. Shows `std::stoi`/`std::stod`/`std::to_string` as the
  parse/convert equivalents of `Integer.parseInt`/`Double.parseDouble`/etc.
- `MathAndRandom.cpp`: `Math.*` -> `<cmath>` (`std::pow`, `std::sqrt`, ...),
  `Math.PI` -> `M_PI`, `java.util.Random` -> `<random>` wrapped in small helper
  functions. Random output differs run-to-run (expected).
- `ObjectReferences.cpp`: value semantics vs references vs pointers -- a major
  Java->C++ difference. Uses pointers to reproduce Java's "reference" behavior.
- `CommonMistakes.cpp`: common beginner traps and their C++ analogs.

## staticexample/

- `Static` (.h/.cpp) + `StaticExample.cpp`: static (shared) vs non-static
  (per-object) members and methods. Note that a static data member must be
  DEFINED once in the .cpp (e.g. `int Static::counter = 0;`).

## strings/

- `String205` (.h/.cpp) + `StringExamples.cpp`: `std::string` methods and a key
  teaching point -- C++ `==` on `std::string` compares VALUE (contents), while
  Java `==` compares references. So the comparison demo prints differently than
  Java does, on purpose.
- `MoreStringExamples.cpp`: case conversion, `substr` (takes a LENGTH, not an
  end index, unlike Java's `substring`), and concatenation with `+`.
- `StringsAndCharacters.cpp`: looping over characters and a `split()` helper
  (C++ `std::string` has no built-in split).
- `Sentences.cpp`: mirrors the Java original whose `main` did nothing; the
  helper functions are present but, as in Java, not called.

## Key Java -> C++ differences highlighted in the comments

- **String `==`**: compares contents in C++, references in Java.
- **References/pointers**: C++ variables are values (copies); use `&`/`*` to get
  Java-style "shared object" reference behavior.
- **No wrappers / no autoboxing**: `int` is just `int`; use `std::stoi` etc.
- **Static members** must be defined in the .cpp, not just declared.
- **`substr(start, length)`** vs Java's `substring(start, end)`.
- **Random/addresses** differ run-to-run; that is expected.
