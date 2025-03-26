#ifndef FRACTION_H
#define FRACTION_H

#include <string>
#include <cmath>

class Fraction {
private:
    int numerator;
    int denominator;

public:
    // Default constructor
    Fraction() {
        numerator = 1;
        denominator = 1;
    }

    // Constructor with parameters
    Fraction(int numerator, int denominator) {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    // Getters
    int getNumerator() const {
        return numerator;
    }

    int getDenominator() const {
        return denominator;
    }

    // Setters
    void setNumerator(int num) {
        numerator = num;
    }

    void setDenominator(int denom) {
        denominator = denom;
    }

    // Convert to mixed number
    std::string toMixedNumber() const {
        std::string result;
        int whole = numerator / denominator;
        int remainder = numerator % denominator;

        if (whole != 0) {
            result += std::to_string(whole) + " ";
        }
        if (remainder != 0) {
            result += std::to_string(remainder) + "/";
            result += std::to_string(std::abs(denominator));
        }
        return result;
    }

    // String representation
    std::string toString() const {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }
};

#endif
