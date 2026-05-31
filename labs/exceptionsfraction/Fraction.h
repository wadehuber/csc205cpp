#ifndef FRACTION_H
#define FRACTION_H

#include <string>

/**
 * Fraction class, including the ability to represent improper fractions
 * as mixed numbers.
 *
 * Activity - add exception handling.
 *
 * @author Wade Huber
 */
class Fraction {
private:
    int numerator;
    int denominator;

public:
    /** Class constructor - default to 1 */
    Fraction();

    /** Class constructor specifying values for numerator & denominator */
    Fraction(int numerator, int denominator);

    int getNumerator() const;
    void setNumerator(int numerator);

    int getDenominator() const;
    void setDenominator(int denominator);

    /** Generate a string representing the fraction in mixed number format. */
    std::string toMixedNumber() const;

    /** String representation of the fraction (e.g. "8/3"). */
    std::string toString() const;
};

#endif
