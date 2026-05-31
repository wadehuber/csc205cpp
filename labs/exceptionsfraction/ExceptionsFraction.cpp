#include <iostream>
#include "Fraction.h"

/**
 * Driver class for CSC205 Activity 2
 *
 * @author Wade Huber
 */
int main() {

    Fraction sampleFraction(8, 3);

    // std::cin is C++'s console input (like Java's Scanner on System.in).
    int value;

    std::cout << "Enter the numerator:  ";
    std::cin >> value;
    sampleFraction.setNumerator(value);

    std::cout << "Enter the denominator:  ";
    std::cin >> value;
    sampleFraction.setDenominator(value);

    std::cout << "The fraction " << sampleFraction.getNumerator() << "/"
              << sampleFraction.getDenominator() << " is equal to "
              << sampleFraction.toMixedNumber() << std::endl;

    return 0;
}
