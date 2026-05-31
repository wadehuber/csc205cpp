# Polymorphism (C++)

C++ conversion of the CSC205 polymorphism video examples. The original Java
videos still explain the concepts:

- payroll [Video](https://youtu.be/UM9QZ2zbFhw) (9:26): introduction to polymorphism
- animals [Video](https://youtu.be/xmad8bledpQ) (11:45): polymorphism using inheritance & interfaces

## Two programs

This directory builds two separate programs:

- **myanimals** - the `MyAnimals` driver. Uses the `animals/` classes plus
  `Airplane`. Shows polymorphism through an abstract base class (`Animal`) and
  an interface-style class (`Flyer`).
- **firm** - the payroll `Firm` driver. Uses `Staff` and the `employees/`
  classes. Shows the classic polymorphic `pay()` over a mixed staff list.

## How Java ideas map to C++

- `extends Base` -> `: public Base`
- `implements Interface` -> `: public Interface`. `Bat`/`Eagle` do both, so they
  use multiple inheritance: `class Bat : public Animal, public Flyer`.
- A Java `interface` (`Flyer`) becomes a header-only class of pure virtual
  functions plus a virtual destructor.
- An `abstract` method (`Animal::speak`, `StaffMember::pay`) becomes a pure
  virtual function (`= 0`). Methods a subclass overrides are declared `virtual`
  in the base and marked `override` in the subclass.
- `super(args)` -> constructor initializer list `: Base(args)`.
  `super.method()` -> `Base::method()`.
- A Java array of mixed subtypes (the animal array, the `Flyer` array, the
  payroll staff list) becomes a `std::vector` of *pointers* to named stack
  objects. No `new`/`delete` is used; calling through the base pointer gives
  dynamic dispatch (polymorphism).
- Java's `toString()` becomes a `virtual std::string toString() const`; we print
  it explicitly with `std::cout << x->toString()`.

## A note on money formatting

Java's `"Paid: " + amount` prints a plain `double` (e.g. `422.0`). The C++
version formats money with two decimals using `<iomanip>`
(`std::fixed << std::setprecision(2)`), so it prints `422.00`. The numeric
values are identical; only the trailing-zero formatting differs.

## Build & run

```
make        # build both programs
make run    # build and run both
make clean  # remove the built programs
```

Requires g++ with C++17 (`-std=c++17 -Wall`).
