# Inheritance (C++ version)

These are C++ translations of the CSC205 inheritance video examples. They keep
the same class names, method names, program flow, and output as the Java
originals; comments point out where C++ does something differently.

The original videos (Java) still explain the concepts:

## Class Design Review

- [VIDEO: Part 1: Cards without class](https://youtu.be/l1QF_ZRas28) (6:19)
- [VIDEO: Part 2: Designing a Card class](https://youtu.be/Hk3yCO9QT-o) (8:30)

## Inheritance

- Example Animal class hierarchy [Video](https://youtu.be/dMZ_c3tCp5U) (14:19)

## Special References

- [Video](https://youtu.be/R7V7-Wx2YCY) (10:52)
- Example of the special references `this` and `super`. Note this example uses
  shadow variables, which are not a good idea in practice, but they show the
  difference between the `this` and `super` references. In C++ the `super`
  reference does not exist; you reach a base member or method by qualifying it
  with the base class name, e.g. `ParentClass::toString()` or
  `ParentClass::myName`. `this` becomes the pointer `this->`.

## Programs and how to build them

Each example folder has its own `Makefile` (g++, `-std=c++17 -Wall`).

### `inheritance/` (animals + overload-vs-override)

Holds two independent programs:

- **myanimals** - the `Animal` / `Dog` / `Cat` / `SugarGlider` hierarchy
  (`MyAnimals.cpp` plus `animals/`).
- **overloadrideexample** - the overload-vs-override example
  (`overloadvsride/`).

```
cd inheritance
make          # builds both programs
make run      # runs both
make clean    # removes the built programs
```

### `specialref/` (this / super)

```
cd specialref
make          # builds specialreferences
make run
make clean
```

## C++ notes for Java programmers

- `extends` becomes `: public Base`. `@Override` becomes the `override` keyword.
- A method meant to be overridden is declared `virtual` in the base class.
  (Java methods are virtual by default; in C++ you say so explicitly.)
- An abstract class is one with at least one **pure virtual** function
  (`= 0`). `Animal::speak()` is pure virtual, so `Animal` cannot be created
  directly. Every polymorphic base class also gets a `virtual ~Base() = default;`.
- `super(args)` in a constructor becomes a base initializer list, e.g.
  `Cat::Cat(std::string name) : Animal(name) {}`.
- `super.method()` becomes `Base::method()`.
- Java uses a base-class **reference** for polymorphism
  (`Animal a = new Dog(...)`). C++ uses a base-class **pointer** to a named
  stack object (`Dog copper("Copper"); Animal* a = &copper;`) and calls
  through it with `a->speak()`. No `new`/`delete` needed.
- **Overload vs override / name hiding:** in `overloadvsride`, `Derived`
  inherits `change(int)` and adds the overloads `change(std::string)` and
  `change(int, std::string)`. In C++, declaring *any* `change` in `Derived`
  *hides* the inherited `change(int)`. We add `using Base::change;` to keep it
  visible, which reproduces the Java behavior where the inherited overload is
  still callable.
- Java calls `toString()` automatically when printing an object; C++ does not,
  so the drivers call `.toString()` explicitly and stream the `std::string`.
