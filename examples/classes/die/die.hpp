#ifndef DIE_H
#define DIE_H

#include <string>

class Die {
private:
    int numberOfSides;  // maximum face value (number of sides)
    int faceValue;      // current value showing on the die

public:
    // Default Constructor: Sets the number of sides to 6
    Die();
    
    // Constructor: Sets the number of sides to numFaces
    explicit Die(int numFaces);
    
    // Accessors & mutators
    int getNumberOfSides() const;
    int getFaceValue() const;
    void setFaceValue(int value);
    
    // Create a new face value and returns the result
    int roll();
    
    // Convert to string representation
    std::string toString() const;
};

#endif // DIE_H
