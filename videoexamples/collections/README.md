# Collections, Generics, & Iterators (C++ version)

These are C++ conversions of the CSC205 Java examples on collections, generic
types, and iterators. The class/method names, program flow, and output mirror
the Java originals as closely as C++ allows. A few C++-specific notes are
called out below (and in comments in the code).

Quick Java -> C++ mapping used throughout:

- `ArrayList` / `List<T>` -> `std::vector<T>`
- `HashMap<K,V>` -> `std::unordered_map<K,V>` (unordered, like Java) or
  `std::map<K,V>` (sorted) when a predictable order is nicer
- enhanced for `for (X x : coll)` -> C++ range-based for `for (X x : coll)`
- generic class `class Foo<T>` -> `template <typename T> class Foo` (header-only)
- generic method `<T> void f(T a)` -> `template <typename T> void f(T a)`
- `toString()` -> a `std::string toString() const` method (and often an
  `operator<<` so the object can be printed with `std::cout`)

Building: each sub-directory has a Makefile.

    make        # build
    make run    # build and run
    make clean  # delete the built program(s)

`IterableExample.cpp` - Iterating two lists in parallel with iterators. Uses
`<random>`, so the actual numbers differ from the Java run (and from run to
run); the logic is the same.

## genericexample

Example of generics in C++.

- `Thing.h` - A generic class (header-only template, like all C++ templates).
- `GenericsExample.cpp` - Uses the generic class and a generic (template)
  function `areSame`.

## Java Collections API (`collections`)

- `ArrayListExample.cpp` - Using `std::vector` (Java's ArrayList): add, index,
  size, indexOf, iterators, range-based for, and a "matrix" (vector of vectors).
- `HashMapExample.cpp` - Using `std::unordered_map` (Java's HashMap). Both are
  unordered/hash-based, so the print ORDER will not match the Java run; the
  data is the same.
- `GradeBook.cpp` - A map whose values are lists of grades. Uses `std::map`
  (sorted by key) so output is predictable; Java's HashMap order differed.

## box

Another generic-class example.

- `Box.h` - A generic class that holds one thing (header-only template).
- `Cat.h` / `Cat.cpp` - A cat to put in the box.
- `BoxDriver.cpp` - Driver. NOTE: Java's `box4` held an
  `ArrayList<Object>` (a mixed-type list). C++ containers are homogeneous, so
  we store each item's text form in a `std::vector<std::string>`; see the
  comments in the driver.

## tasklist

Implementing a collection backed by a `std::vector`.

- `Priority.h` - An abstract base class (Java interface) for things with a
  priority.
- `Task.h` / `Task.cpp` - A Task that "implements" Priority (inherits it).
- `ToDoList.h` - An abstract base class for a to-do list.
- `GetItDone.h` / `GetItDone.cpp` - A collection of Tasks. Provides both a
  Java-style `iterator()` (`hasNext()`/`next()`) and C++ `begin()`/`end()` so a
  range-based for loop works.
- `TaskDriver.cpp` - Driver that builds and prints a to-do list.

## iterators

Writing your own iterator.

- `EvenNumbers.h` - A class that yields even numbers. Provides both a
  Java-style `hasNext()`/`next()` and C++ `begin()`/`end()`.
- `IteratorExample.cpp` - Uses the EvenNumbers iterator.
- `StringIterator.cpp` - A `std::string` is already a sequence of characters,
  so a range-based for loop walks it directly (no `toCharArray()` needed).
