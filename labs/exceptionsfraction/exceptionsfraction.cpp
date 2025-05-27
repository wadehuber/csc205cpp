#include <iostream>
#include "fraction.hpp"

int main() {
    Fraction sampleFraction(8, 3);

    int num, denom;

    std::cout << "Enter the numerator:  ";
    std::cin >> num;
    sampleFraction.setNumerator(num);

    std::cout << "Enter the denominator:  ";
    std::cin >> denom;
    sampleFraction.setDenominator(denom);

    std::cout << "The fraction " << sampleFraction.getNumerator() << "/"
              << sampleFraction.getDenominator()
              << " is equal to " << sampleFraction.toMixedNumber() << std::endl;

    return 0;
}
