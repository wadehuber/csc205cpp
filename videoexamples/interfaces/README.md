# Interfaces

C++ versions of the CSC205 "interfaces" video examples. The original videos use
Java; the notes below point out how each Java idea maps to C++.

Java has a dedicated `interface` keyword and a built-in `Comparable` interface.
C++ has neither, so:

- A Java `interface` becomes a C++ class containing ONLY pure virtual functions
  (`= 0`) plus a `virtual ~Name() = default;`. `implements X` becomes
  `: public X`, and `@Override` becomes `override`.
- Java's `Comparable<T>` / `compareTo` has no C++ equivalent, so we just keep a
  `int compareTo(const T& o) const` method that returns a negative / zero /
  positive value, exactly like Java. (The idiomatic C++ approach would be to
  overload `operator<`, but we keep `compareTo` to match the lesson.)

Each program has its own `Makefile`:

```
make        # build the program
make run    # build and run it
make clean  # delete the built program
```

## interfaces

[Video](https://youtu.be/YKzHAUyg7fY) (9:54): Example of an interface in Java.

`MyInterface.h` is the interface (pure virtual `add` and `greet`). `MyClass`
and `MyOtherClass` implement it. `InterfaceDriver.cpp` has `main`.

Note: Java's interface constant `final int MYNUM = 42;` becomes a
`static constexpr int MYNUM = 42;` on the C++ interface.

```
make run   # builds and runs interfacedriver
```

## The Comparable interface

Video - [Introduction to the Comparable Interface & the compareTo method](https://youtu.be/1BOhHUp7jc4) (5:37)

### compareto

- [Video](https://youtu.be/W08z47vuX2Y) (6:28): example of implementing a class
  that implements the Comparable interface.

`compareto/MyClass` keeps the Java `compareTo` (`return this->num - o.num;`).
`CompareTo.cpp` has `main`. In C++ we print objects with an explicit
`x.toString()` call instead of Java's automatic string concatenation.

```
cd compareto
make run   # builds and runs compareto
```

### movies

- [Video](https://youtu.be/wxfb2JxEOtI) (9:11): Another example of designing a
  `compareTo` method.

`movies/Movie` compares on IMDB rating, breaking ties with Rotten Tomatoes.
`MoviePicker.cpp` has `main` and finds the best movie.

```
cd movies
make run   # builds and runs moviepicker
```
