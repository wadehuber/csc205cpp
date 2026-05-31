# Writing Classes (C++ version)

C++ versions of the CSC205 "Writing Java Classes" video examples. The original
videos use Java; the notes below point out how each Java idea maps to C++.

[VIDEO: CSC205 Overview](https://youtu.be/gnjN6ULSnAs)

Each sub-directory has its own `Makefile`:

```
make        # build the program(s)
make run    # build and run them
make clean  # delete the built program(s)
```

On Windows, use `mingw32-make` if you installed MinGW-w64.

General differences from Java in these examples:

- Each Java class becomes a `.h` (declarations) + `.cpp` (definitions). Driver
  classes with `main` become a single `.cpp`.
- Java prints objects by automatic `toString()` calls during string
  concatenation. C++ has no such thing, so every class gets a
  `std::string toString() const` and we print with
  `std::cout << x.toString()`.

## formattingoutput

- `FormattingDoubles.cpp` [VIDEO](https://youtu.be/WgT7T6B5l8E) (3:48): Java used
  a `DecimalFormat` object to format doubles. C++ has no `DecimalFormat`, so we
  reproduce the patterns `#`, `#.##`, and `#,###.##` with small helper functions
  built on `<iomanip>`/`<sstream>` (rounding, dropping trailing zeros, and
  inserting comma thousands-separators by hand).
- `PrintfExample.cpp` [VIDEO](https://youtu.be/13utNMhCVgA) (2:42): Java's
  `System.out.printf` / `System.out.format` map almost 1-to-1 onto `printf` from
  `<cstdio>` with the same `%s`, `%d`, `%.2f`, and width specifiers. The only
  twist is passing `name.c_str()` for `%s`.
- `NumberFormatting.cpp` [VIDEO](https://youtu.be/zaTXwXJW328) (3:34): Java used
  `NumberFormat` for percents and money. C++ has no `NumberFormat` (locale-based
  formatting exists but is verbose), so we format currency and percentages with
  small helpers.

```
cd formattingoutput
make run
```

## pen

- [VIDEO](https://youtu.be/PPDCGPH_ef0) (10:01)
- `FourColorPen.h` / `FourColorPen.cpp`: class modeling a 4-color pen. Java's
  `private static final String[]` of color names becomes a
  `static const std::vector<std::string>` member (declared in the header,
  defined once in the `.cpp`). Java's `String.toUpperCase()` has no C++
  equivalent, so we provide a small `toUpperCase` helper.
- `PenDriver.cpp`: driver with `main`.

```
cd pen
make run
```

## die

- [VIDEO](https://youtu.be/mb0LYsgkpTo) (17:40)
- `Die.h` / `Die.cpp`: class modeling a 6-sided die. Java's `Math.random()`
  becomes a `<random>` helper (`std::mt19937` + `std::uniform_real_distribution`,
  seeded once). The default constructor delegates to `Die(6)`, just like Java's
  `this(6)`.
- `SnakeEyes.cpp`: driver with `main`. Repeatedly rolls a pair of dice and
  counts how often both show 1. The random output differs from run to run (and
  from Java) -- that is expected.

```
cd die
make run
```

## tostring

- [VIDEO](https://youtu.be/dNr3JATBsd0) (8:52): several ways to write a
  `toString`, including a few bad ones.
- `Movie.h` / `Movie.cpp`: an example class. Java's `long` field becomes
  `long long` in C++ (guaranteed 64-bit).
- `ToStringExample.cpp`: builds a `std::vector<Movie>` (Java used an array) and
  prints each movie with `toString()`.

```
cd tostring
make run
```
