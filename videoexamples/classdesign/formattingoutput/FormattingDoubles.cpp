// FormattingDoubles.cpp
// C++ version of FormattingDoubles.java
//
// Java used java.text.DecimalFormat to format doubles with patterns like
// "#", "#.##", and "#,###.##". C++ has NO DecimalFormat class, so we
// reproduce the same three behaviors with small helper functions built on
// <iomanip>/<sstream> and explain the differences:
//
//   "#"        -> round to a whole number, no decimal point          (fmt1)
//   "#.##"     -> up to 2 decimals, drop trailing zeros and the dot   (fmt2)
//   "#,###.##" -> same as #.## but with comma thousands-separators    (fmt3)
//
// Note: std::fixed << setprecision(2) always prints EXACTLY 2 decimals
// (e.g. 12.30), whereas Java's "#.##" DROPS trailing zeros (12.3). So we
// format with fixed precision and then trim the trailing zeros ourselves to
// match Java's output.

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// Round to a whole number (DecimalFormat "#"). Java rounds half-up; we use
// std::llround which also rounds half away from zero.
std::string formatNoDecimals(double value) {
    return std::to_string(std::llround(value));
}

// Trim trailing zeros (and a trailing '.') from a fixed-precision string,
// reproducing how DecimalFormat's "#.##" drops insignificant zeros.
static std::string trimTrailingZeros(std::string s) {
    if (s.find('.') == std::string::npos) {
        return s;
    }
    while (!s.empty() && s.back() == '0') {
        s.pop_back();
    }
    if (!s.empty() && s.back() == '.') {
        s.pop_back();
    }
    return s;
}

// Up to 2 decimal places, trailing zeros dropped (DecimalFormat "#.##").
std::string formatTwoDecimals(double value) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << value;
    return trimTrailingZeros(oss.str());
}

// Insert comma thousands-separators into the integer part of a number string.
// Java's "#,###.##" does this automatically; C++ has no built-in for it
// (std::locale grouping is possible but fiddly), so we do it by hand.
static std::string addCommas(std::string number) {
    bool negative = (!number.empty() && number[0] == '-');
    if (negative) {
        number.erase(0, 1);
    }

    std::string intPart = number;
    std::string fracPart;
    size_t dot = number.find('.');
    if (dot != std::string::npos) {
        intPart = number.substr(0, dot);
        fracPart = number.substr(dot);  // includes the '.'
    }

    std::string grouped;
    int digitsSinceComma = 0;
    for (int ii = (int)intPart.size() - 1; ii >= 0; ii--) {
        grouped.insert(grouped.begin(), intPart[ii]);
        digitsSinceComma++;
        if (digitsSinceComma == 3 && ii > 0) {
            grouped.insert(grouped.begin(), ',');
            digitsSinceComma = 0;
        }
    }

    return (negative ? "-" : "") + grouped + fracPart;
}

// Comma-separated, up to 2 decimals, trailing zeros dropped ("#,###.##").
std::string formatCommas(double value) {
    return addCommas(formatTwoDecimals(value));
}

int main() {
    double number1 = 12.3456789;
    double number2 = 98.7654321;
    double number3 = 1234567890.555;
    double number4 = .0000000000000009;

    std::cout << "No formatting: " << std::endl;
    // Plain stream output of a double (the closest analog to Java's default
    // System.out.println of a double). Very small/large values may print in
    // scientific notation, similar to Java.
    std::cout << "  " << number1 << std::endl;
    std::cout << "  " << number2 << std::endl;
    std::cout << "  " << number3 << std::endl;
    std::cout << "  " << number4 << std::endl;

    std::cout << std::endl;
    std::cout << "fmt1 # - no decimal places: " << std::endl;
    std::cout << "  " << formatNoDecimals(number1) << std::endl;
    std::cout << "  " << formatNoDecimals(number2) << std::endl;
    std::cout << "  " << formatNoDecimals(number3) << std::endl;
    std::cout << "  " << formatNoDecimals(number4) << std::endl;

    std::cout << std::endl;
    std::cout << "fmt2 #.## - 2 decimal places: " << std::endl;
    std::cout << "  " << formatTwoDecimals(number1) << std::endl;
    std::cout << "  " << formatTwoDecimals(number2) << std::endl;
    std::cout << "  " << formatTwoDecimals(number3) << std::endl;
    std::cout << "  " << formatTwoDecimals(number4) << std::endl;

    std::cout << std::endl;
    std::cout << "fmt3 #,###.## - Comma-separated, 2 decimal places: " << std::endl;
    std::cout << "  " << formatCommas(number1) << std::endl;
    std::cout << "  " << formatCommas(number2) << std::endl;
    std::cout << "  " << formatCommas(number3) << std::endl;
    std::cout << "  " << formatCommas(number4) << std::endl;

    return 0;
}
