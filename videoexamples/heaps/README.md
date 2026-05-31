# Heaps (C++ translation)

This directory is a C++ translation of the CSC205 "Java Foundations" (jsjf)
heaps package. The algorithms (heap ordering, BST insertion, heap sort,
priority-queue ordering) are preserved exactly; only the language was changed
so it can be read by students who may only know Java.

## Introductory videos

(The videos below were recorded against the Java version, but every data
structure and algorithm shown is reproduced here unchanged.)

[Video: Overview of Heaps & Priority Queues](https://youtu.be/cRzgDdtvgCI) (7:24)

### Implementing Heaps

  - Video 1 of 3: [Introduction to min & max heaps, HeapNode, & LinkedHeap](https://youtu.be/sj6QqonekkY) (7:55)
  - Video 2 of 3: [Adding elements to a min heap](https://youtu.be/D4ywzZn2jo0) (10:07)
  - Video 3 of 3: [Removing elements from a min heap](https://youtu.be/z3tFZVaJTGQ) (9:11)

## Code

  - [Video 1 - Using heaps, HeapADT interface, HeapNode class, Linked Heap class, adding elements](https://youtu.be/gypH36ka7Ls) (11:28)
  - [Video 2 - Removing elements from a min heap - removeMin()](https://youtu.be/MIIyYW2I2dI) (7:00)

### Utility classes

- `HeapExample.cpp`  - example of using a Heap (driver with `int main()`)
- `StudentRecord.h`  - class we add to a Heap
- `SortPhoneList.cpp`- example of using heapSort (driver with `int main()`)
- `Contact.h`        - class we sort using heapSort

### jsjf

The new files for this module are:

- `jsjf/HeapADT.h`   - Heap interface
- `jsjf/ArrayHeap.h` - array implementation of a Heap
- `jsjf/LinkedHeap.h`- linked implementation of a Heap
- `jsjf/HeapNode.h`  - Heap Node class

Several supporting classes were imported from earlier modules
(`ArrayBinaryTree`, `LinkedBinaryTree`, `LinkedBinarySearchTree`,
`BinaryTreeNode`, `ArrayList`, `ArrayUnorderedList`, the `*ADT` interfaces,
and the `exceptions/` classes).

### csc205

[Video - HeapSort](https://youtu.be/p9SA1cD5GW8) (1:36)

- `csc205/Sorting.h` - Sorting class that includes `heapSort` (and several
  other classic sorts)

### priorityqueue

Videos:

- [Overview of Priority Queues & the Prioritized Object class](https://youtu.be/4OULGDYpzJI) (10:06)
- [Code walk through](https://youtu.be/H_eCyBqLlGQ) (5:44)

Code:

- `priorityqueue/PriorityQueue.h`     - priority queue built on a Heap
- `priorityqueue/PrioritizedObject.h` - helper object for the priority queue
- `priorityqueue/PQTester.cpp`        - priority queue test driver (`int main()`)

## How the Java was translated to C++

This package is intricate, so a few conventions are worth calling out:

- **Header-only templates.** Java generics (`class Foo<T>`) become C++ class
  templates (`template <typename T>`). Because the compiler must see a whole
  template to instantiate it, every generic class lives entirely in a `.h`
  file with **no** matching `.cpp`. Only the three drivers
  (`HeapExample.cpp`, `SortPhoneList.cpp`, `PQTester.cpp`) are `.cpp` files
  with a `main()`.

- **Interfaces.** Each Java `interface` (`HeapADT`, `BinaryTreeADT`,
  `BinarySearchTreeADT`, `ListADT`, `UnorderedListADT`) became a class template
  with only pure virtual functions plus a virtual destructor. Where two of
  these meet in a diamond (e.g. `ArrayHeap` is both a `BinaryTreeADT` and a
  `HeapADT`), the shared interface is inherited `virtual` so there is a single
  shared base.

- **Comparable.** Java's `((Comparable<T>)a).compareTo(b) < 0` and `.equals()`
  become `a < b` (`operator<`) and `a == b` (`operator==`). The element types
  used here (`int`, `std::string`, `Contact`, `StudentRecord`,
  `PrioritizedObject`) define those operators with the same logic as the Java
  `compareTo`/`equals`.

- **Node memory.** Linked structures use **raw pointers + `new` + `nullptr`**
  to mirror Java exactly. Java's garbage collector freed nodes automatically;
  in C++ we add **destructors** that `delete` nodes (a node's destructor
  recursively deletes its children, so deleting a tree's root frees the whole
  tree). `LinkedHeap::removeMin` also `delete`s the single node it detaches.
  All three programs run clean under Valgrind (no leaks).

- **Exceptions.** The custom exceptions derive from `std::runtime_error`; the
  message is read with `.what()`. `throw new X("msg")` becomes
  `throw X("msg")`, caught by `const X&`.

- **`toString()`.** Each class provides `std::string toString() const`, printed
  with `std::cout << x.toString()`. The trees print elements through a small
  `elementToString` helper so that both `LinkedHeap<int>` and
  `LinkedHeap<StudentRecord>` print correctly (Java relied on every element
  being an `Object` with `toString()`).

## Building and running

A `Makefile` at this level builds the two drivers here; the priority queue
has its own `Makefile` in `priorityqueue/`.

```
make            # build HeapExample and SortPhoneList
make run        # build and run both
make clean      # remove the built programs

cd priorityqueue
make            # build PQTester
make run        # build and run it
make clean
```

(Use `mingw32-make` on Windows with MinGW-w64.)

## A note on output

`HeapExample` fills its integer heap and binary search tree with **random**
numbers (Java used `Math.random()`, C++ uses `<random>`), so the `Tree k:`
and `Heap t:` lines change every run and will not match the Java output
character-for-character. This is by design and matches the original program.
The `StudentRecord` heap (`Heap s:`), the `removeMin` results, the sorted
phone list, and the priority-queue ordering are all deterministic and match
the Java program exactly.
