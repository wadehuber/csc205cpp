// MathAndRandom.cpp
// C++ version of MathAndRandom.java
//
// Java review topic: the Math and Random classes.
//   - Java's Math.* methods live in <cmath> in C++ as std::pow, std::sqrt,
//     std::abs/std::fabs, std::log, std::log10, std::exp, std::sin/cos/tan,
//     std::round/std::floor/std::ceil, std::min/std::max.
//   - Java's Math.PI becomes M_PI. M_PI is not standard, so we define
//     _USE_MATH_DEFINES before including <cmath> (and define it ourselves
//     as a fallback).
//   - Math.toRadians(d) is just d * M_PI / 180.
//   - java.util.Random becomes <random>: a std::mt19937 generator plus
//     distribution objects. We wrap them in small helper functions, seeded
//     once, to mirror nextInt / nextInt(10) / nextDouble / nextBoolean.
//
// The random numbers will differ from run to run (and from Java) -- that is
// expected and correct.

#define _USE_MATH_DEFINES
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <iostream>
#include <random>

// ---- Random helpers (one generator, seeded once) -------------------------
// A single generator shared by the helpers, seeded from the system clock.
static std::mt19937& generator() {
    static std::mt19937 gen(std::random_device{}());
    return gen;
}

// Like Java's rand.nextInt(): any int across the full range.
int randomInt() {
    std::uniform_int_distribution<int> dist;  // full int range
    return dist(generator());
}

// Like Java's rand.nextInt(maxExclusive): 0 .. maxExclusive-1
int randomInt(int maxExclusive) {
    std::uniform_int_distribution<int> dist(0, maxExclusive - 1);
    return dist(generator());
}

// Like Java's rand.nextDouble(): a double in [0.0, 1.0)
double randomDouble() {
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(generator());
}

// Like Java's rand.nextBoolean(): true/false with equal probability
bool randomBool() {
    std::bernoulli_distribution dist(0.5);
    return dist(generator());
}

int main() {
    std::cout << "java.lang.Math" << std::endl;
    std::cout << "  Math.PI = " << M_PI << std::endl;
    std::cout << "  Math.abs(6) = " << std::abs(6) << std::endl;
    std::cout << "  Math.abs(-6) = " << std::abs(-6) << std::endl;
    std::cout << std::endl;

    std::cout << "Exponents" << std::endl;
    std::cout << "  Math.pow(2, 8) = " << std::pow(2, 8) << std::endl;
    std::cout << "  Math.pow(27, 1.0 / 3.0) = " << std::pow(27, 1.0 / 3.0) << std::endl;
    std::cout << "  Math.pow(2, -2) = " << std::pow(2, -2) << std::endl;
    std::cout << "  Math.exp(1) = " << std::exp(1) << std::endl;
    std::cout << "  Math.exp(-1) = " << std::exp(-1) << std::endl;
    std::cout << "  Math.exp(2) = " << std::exp(2) << std::endl;
    std::cout << std::endl;

    std::cout << "Logarithms" << std::endl;
    std::cout << "  Math.log(10) = " << std::log(10) << std::endl;
    std::cout << "  Math.log(Math.exp(1)) = " << std::log(std::exp(1)) << std::endl;
    std::cout << "  Math.log10(10) = " << std::log10(10) << std::endl;
    std::cout << "  Math.log10(1000) = " << std::log10(1000) << std::endl;
    std::cout << "  Logs base 2:" << std::endl;
    std::cout << "     1/4 : " << std::log10(.25) / std::log10(2) << std::endl;
    std::cout << "     2 : " << std::log10(2) / std::log10(2) << std::endl;
    std::cout << "     16 : " << std::log10(16) / std::log10(2) << std::endl;
    std::cout << std::endl;

    std::cout << "Minimum & Maximum" << std::endl;
    std::cout << "  Math.min(7, 8) = " << std::min(7, 8) << std::endl;
    std::cout << "  Math.max(7, 8) = " << std::max(7, 8) << std::endl;
    std::cout << "  Math.min(4.2, 3.1) = " << std::min(4.2, 3.1) << std::endl;
    // (mirrors the Java original, which actually passed 7 and 3.1 here)
    std::cout << "  Math.max(4.2, 3.1) = " << std::max(7.0, 3.1) << std::endl;
    std::cout << std::endl;

    std::cout << "Round, Floor, & Ceiling" << std::endl;
    std::cout << "  Math.round(9.1) = " << std::round(9.1) << std::endl;
    std::cout << "  Math.round(9.5) = " << std::round(9.5) << std::endl;
    std::cout << "  Math.round(9.9) = " << std::round(9.9) << std::endl;
    std::cout << "  Math.floor(9.1) = " << std::floor(9.1) << std::endl;
    std::cout << "  Math.floor(9.5) = " << std::floor(9.5) << std::endl;
    std::cout << "  Math.floor(9.9) = " << std::floor(9.9) << std::endl;
    std::cout << "  Math.ceil(9.1) = " << std::ceil(9.1) << std::endl;
    std::cout << "  Math.ceil(9.5) = " << std::ceil(9.5) << std::endl;
    std::cout << "  Math.ceil(9.9) = " << std::ceil(9.9) << std::endl;
    std::cout << std::endl;

    std::cout << "Trig Functions" << std::endl;
    double angle1 = M_PI / 6.0;
    double angle2 = M_PI / 2.0;
    double angle3 = 45 * M_PI / 180;   // Math.toRadians(45)
    std::cout << "  Angle 1: " << angle1 << std::endl;
    std::cout << "     Math.cos = " << std::cos(angle1) << std::endl;
    std::cout << "     Math.sin = " << std::sin(angle1) << std::endl;
    std::cout << "     Math.tan = " << std::tan(angle1) << std::endl;
    std::cout << "  Angle 2: " << angle2 << std::endl;
    std::cout << "     Math.cos = " << std::cos(angle2) << std::endl;
    std::cout << "     Math.sin = " << std::sin(angle2) << std::endl;
    std::cout << "     Math.tan = " << std::tan(angle2) << std::endl;
    std::cout << "  Angle 3: " << angle3 << std::endl;
    std::cout << "     Math.cos = " << std::cos(angle3) << std::endl;
    std::cout << "     Math.sin = " << std::sin(angle3) << std::endl;
    std::cout << "     Math.tan = " << std::tan(angle3) << std::endl;
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "java.lang.Random" << std::endl;
    std::cout << "  nextInt(): ";
    for (int ii = 0; ii < 10; ii++) {
        std::cout << "  " << randomInt();
    }
    std::cout << std::endl;

    std::cout << "  nextInt(10): ";
    for (int ii = 0; ii < 10; ii++) {
        std::cout << "  " << (randomInt(10) + 1);
    }
    std::cout << std::endl;

    std::cout << "  nextDouble(): ";
    for (int ii = 0; ii < 10; ii++) {
        std::cout << "  " << randomDouble();
    }
    std::cout << std::endl;

    // Print bools as true/false (like Java) instead of C++'s default 1/0.
    std::cout << "  nextBoolean(): " << std::boolalpha;
    for (int ii = 0; ii < 10; ii++) {
        std::cout << "  " << randomBool();
    }
    std::cout << std::noboolalpha << std::endl;

    return 0;
}
