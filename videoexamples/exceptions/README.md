# Exceptions (C++ version)

C++ versions of the CSC205 Java exception video examples. The code stays as
close to the Java as possible (same class names, method names, output, and
flow) while using idiomatic C++ where it makes sense.

## How C++ exceptions differ from Java (quick reference)

- A custom exception derives from `std::runtime_error` (include `<stdexcept>`)
  and passes its message up via the base constructor.
- `throw new X(...)` (Java) becomes `throw X(...)` -- you throw **by value**.
- `catch (X e)` (Java) becomes `catch (const X& e)` -- catch **by const reference**.
- Read the message with `e.what()`, not Java's `getMessage()`.
- Java's broad `catch (Exception e)` becomes `catch (const std::exception& e)`.
- **No `finally`**: C++ has no `finally` block. Either put the cleanup code
  after the try/catch, or (better) use RAII -- an object whose destructor does
  the cleanup automatically when it goes out of scope.
- **No automatic divide-by-zero exception**: in C++, integer `x / 0` is
  undefined behavior (it usually crashes) and does NOT throw. Several examples
  throw an exception on purpose to demonstrate the same idea Java showed.
- **`std::cin >> num` does not throw** on bad input (Java's `nextInt()` threw
  `InputMismatchException`). Instead `cin` enters a fail state, which we detect
  with `if (!(std::cin >> num))` and then throw ourselves.

## Examples (root level)

Build everything with `make` (uses the Makefile here).

- `ExceptionExample.cpp` -- try/catch plus the C++ stand-in for `finally`
  (cleanup after the try/catch).
- `ExceptionExample2.cpp` -- shows that the "finally" cleanup runs on both the
  early-return (catch) path and the normal path.
- `ExceptionProp.cpp` -- exception propagation: thrown deep in `function4`,
  caught back up in `function2`.
- `ExceptionsMultiCatch.cpp` -- catching several exception types; uses
  `std::vector::at()` (which throws `std::out_of_range`) for the
  out-of-bounds case.
- `FinallyExample.cpp` -- reads a number from `std::cin`; shows fail-state
  handling and "finally"-style cleanup. (Reads stdin, so run it directly.)

(The Java folder listed a `FileIOExample` video and an empty `ExceptionMethods`
class; neither had usable code to convert, so they are not included here.)

## creatingexcept

`CreatingExceptions.cpp` + `YouDidTheWrongThingException.h` -- defining and
throwing your own exception type (derived from `std::runtime_error`). Reads a
number from stdin. Build with the Makefile in that folder.

## defining

`BankAccount.cpp` (+ `BankAccount.h`) + `InsufficientFundsException.h` -- a
custom exception that carries an extra field (`amount`) with a `getAmount()`
getter, just like the Java. `BankAccount.cpp` holds `main()` and the account
methods and uses the exception; they compile together.

## trywithresources

`TryWithResourcesExample.cpp` + `OpenClose.cpp`/`.h` -- the C++ equivalent of
Java's try-with-resources. There is no try-with-resources in C++; instead
`OpenClose`'s **destructor** does the "close" (RAII), and an object declared in
an inner `{ }` scope is closed automatically at the end of that scope. An
explicit `close()` method is kept too, so the example stays 1-1 with the Java
that closed `oc1` by hand.

## Building

Each folder has a `Makefile` with `make`, `make run`, and `make clean`
targets (`g++ -std=c++17 -Wall`). On Windows with MinGW-w64 use
`mingw32-make`.
