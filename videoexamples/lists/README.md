# Linked Lists (C++ translation)

This is a C++ translation of the CSC205 "Linked Lists" Java examples, intended
for students who may only know Java. The algorithms, class/method names, program
flow, and output are kept as close to the Java originals as possible -- only the
language has changed.

## Introductory videos

These videos give a brief overview of the types of lists and of how linked lists
work. The code below matches the Java shown in the videos.

- VIDEO - [Overview of Lists](https://youtu.be/yJaQzOTTtBw) (5:42)
- VIDEO - [Overview of Linked Lists - Implementation & Operations](https://youtu.be/tDTx50zsji0) (11:33)

## csc205

This package contains a simplified, from-scratch linked list implementation
(a different implementation than the one in the jsjf package).

- [Video 1](https://youtu.be/qNkHOvEjh_o) (16:06) - add, toString, size, first, last
- [Video 2](https://youtu.be/fSzkr4H26oQ) (20:25) - remove operations and contains()
- [Video 3](https://youtu.be/BeWXZ4zHl5M) (7:54) - an iterator for our linked list

Source code

- `csc205/LinkedList.h` - Linked list implementation (header-only template)
- `LinkedListDriver.cpp` - Program that uses the linked list (has `main`)

## jsjf

The jsjf package contains code from the Java Foundations book.

- `jsjf/ArrayList.h` [Video](https://youtu.be/8E30B3HuHBY) (12:19) - array-backed list
- `jsjf/LinkedList.h` & `jsjf/LinearNode.h` [Video](https://youtu.be/0YnvMDdBgsM) (9:49) - linked list with a separate node class
- Ordered Lists [Video](https://youtu.be/_jChwaHlqM4) (5:50) - `jsjf/ArrayOrderedList.h`, `jsjf/LinkedOrderedList.h`
- Unordered Lists [Video](https://youtu.be/pbbEEZ7vmqA) (7:19) - `jsjf/ArrayUnorderedList.h`, `jsjf/LinkedUnorderedList.h`

`ListExamples.cpp` (has `main`) exercises the array-based ordered/unordered lists.

## Building and running

A `Makefile` is provided (g++, `-std=c++17 -Wall`). From this directory:

```
make        # build both programs (LinkedListDriver and ListExamples)
make run    # build and run both
make clean  # delete the built programs
```

On Windows, use `mingw32-make` if you installed MinGW-w64.

## Notes on the Java-to-C++ translation

- **Generics -> templates.** Java's `LinkedList<T>` becomes a C++
  `template <typename T>`. Generic classes are **header-only** (everything in the
  `.h`, no `.cpp`). Only the two drivers are `.cpp` files with `main`.

- **Interfaces -> abstract class templates.** `ListADT`, `OrderedListADT`, and
  `UnorderedListADT` become class templates of pure virtual functions (`= 0`)
  with a virtual destructor. Where a concrete list inherits from both a base
  list and an ADT interface (Java's "extends X implements Y"), the ADTs inherit
  **virtually** from `ListADT` so there is a single shared base subobject
  (the C++ way to handle the inheritance "diamond").

- **Node memory.** Java created nodes with `new` and relied on garbage
  collection. C++ has no GC, so we mirror Java with **raw pointers** (`new` /
  `nullptr`) and add **destructors** that walk the chain and `delete` every node.
  Removal methods also `delete` the node they unlink. `null` becomes `nullptr`.

- **Comparable.** Java's `compareTo` / `.equals()` become C++ `operator<` /
  `operator==`. The built-in element types used here (`int`, `std::string`)
  already provide these. The runtime `instanceof Comparable` check becomes a
  compile-time requirement (the element type must define `operator<`).

- **Exceptions.** `ElementNotFoundException`, `EmptyCollectionException`, and
  `NonComparableElementException` derive from `std::runtime_error`; the message
  is read with `.what()`. The csc205 list throws `std::out_of_range` where Java
  threw `NoSuchElementException`.

- **toString.** Built with `std::ostringstream` and printed via
  `std::cout << x.toString()`.

- **Randomness in ListExamples.** Java used `java.util.Random`; C++ uses
  `<random>`. The numbers differ from run to run (as they did in Java), but the
  logic is the same: the ordered list comes out sorted ascending, the
  `addToFront` list is the reverse of the `addToRear` list.
