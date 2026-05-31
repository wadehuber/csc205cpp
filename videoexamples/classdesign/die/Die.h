#ifndef DIE_H
#define DIE_H

#include <string>

// C++ version of Die.java -- models a 6-sided die.
class Die {
private:
    int numberOfSides;   // maximum face value (number of sides)
    int faceValue;       // current value showing on the die

public:
    // Default constructor: sets the number of sides to 6.
    // In Java this used this(6) to delegate to the other constructor.
    // C++ supports delegating constructors too, with the same idea.
    Die();

    // Constructor: sets the number of sides to numFaces.
    Die(int numFaces);

    // Accessors & mutators
    int getNumberOfSides() const;
    int getFaceValue() const;
    void setFaceValue(int value);

    // Creates a new face value and returns the result.
    int roll();

    std::string toString() const;
};

#endif
