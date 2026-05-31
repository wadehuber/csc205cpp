#include "Die.h"

#include <random>
#include <string>

// ---- Random helper (one generator, seeded once) --------------------------
// Java used Math.random() (a double in [0.0, 1.0)). The idiomatic C++ way is
// <random>: a std::mt19937 generator plus a distribution, seeded once and
// wrapped in a small helper so the call site stays simple.
static double randomDouble() {
    static std::mt19937 gen(std::random_device{}());
    static std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(gen);
}

// Default constructor delegates to Die(6), just like Java's this(6).
Die::Die() : Die(6) {
}

Die::Die(int numFaces) {
    numberOfSides = numFaces;
    setFaceValue(1);
}

int Die::getNumberOfSides() const {
    return numberOfSides;
}

int Die::getFaceValue() const {
    return faceValue;
}

void Die::setFaceValue(int value) {
    if (value > 0 && value <= numberOfSides) {
        this->faceValue = value;
    }
}

int Die::roll() {
    // Same formula as Java: (int)(Math.random() * numberOfSides) + 1
    setFaceValue((int)(randomDouble() * numberOfSides) + 1);
    return faceValue;
}

std::string Die::toString() const {
    // std::to_string converts the int to text, like Java's automatic
    // string concatenation with an int.
    return "[" + std::to_string(faceValue) + "]";
}
