#include "Fraction.h"
#include <cstdlib>   // std::abs

Fraction::Fraction() {
    numerator = 1;
    denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
}

int Fraction::getNumerator() const {
    return numerator;
}

void Fraction::setNumerator(int numerator) {
    this->numerator = numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::setDenominator(int denominator) {
    this->denominator = denominator;
}

std::string Fraction::toMixedNumber() const {
    std::string ret = "";
    int remainder = numerator % denominator;

    if (numerator / denominator != 0) {
        ret += std::to_string(numerator / denominator);
        ret += " ";
    }
    if (remainder != 0) {
        ret += std::to_string(numerator % denominator);
        ret += "/";
        ret += std::to_string(std::abs(denominator));
    }

    return ret;
}

std::string Fraction::toString() const {
    std::string ret = std::to_string(numerator) + "/" + std::to_string(denominator);
    return ret;
}
