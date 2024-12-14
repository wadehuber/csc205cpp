// Die.cpp
#include "die.hpp"
#include <random>
#include <sstream>

// Default constructor
Die::Die() : Die(6) {}

// Constructor with number of faces
Die::Die(int numFaces) : numberOfSides(numFaces) {
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
        faceValue = value;
    }
}

int Die::roll() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, numberOfSides);
    
    setFaceValue(dis(gen));
    return faceValue;
}

std::string Die::toString() const {
    std::ostringstream oss;
    oss << "[" << faceValue << "]";
    return oss.str();
}
