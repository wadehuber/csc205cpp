// NumberFormatting.cpp
// C++ version of NumberFormatting.java
//
// Java used java.text.NumberFormat to make currency ($1,234.56) and percent
// (20%) strings. C++ has NO NumberFormat class. You CAN get currency/percent
// formatting via <locale> (std::money_put, etc.), but it is verbose and
// locale-dependent. For a teaching example it is simpler and clearer to format
// the values ourselves, so this file builds the same output with small helpers.
//
//   NumberFormat.getCurrencyInstance() -> formatMoney() below ($, commas, 2 dp)
//   NumberFormat.getPercentInstance()  -> formatPercent() below (x100 + '%')

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// 20% income tax. Java used "final static double"; C++ uses constexpr.
constexpr double INCOME_TAX_RATE = 0.20;

// Insert comma thousands-separators into the integer part of a number string.
static std::string addCommas(const std::string& intPart) {
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
    return grouped;
}

// Like NumberFormat.getCurrencyInstance(): "$" + comma-grouped + 2 decimals.
std::string formatMoney(double value) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << value;
    std::string s = oss.str();

    size_t dot = s.find('.');
    std::string intPart = s.substr(0, dot);
    std::string fracPart = s.substr(dot);  // includes the '.'

    return "$" + addCommas(intPart) + fracPart;
}

// Like NumberFormat.getPercentInstance(): multiply by 100 and add '%'.
// (getPercentInstance prints no decimals for a whole percentage, so we round.)
std::string formatPercent(double value) {
    return std::to_string(std::llround(value * 100)) + "%";
}

int main() {
    int salary = 75000;

    // Java: "salary / 52" is INTEGER division (both operands are int), giving
    // 1442, which is then stored in a double. C++ does the same: int / int is
    // integer division here, so weeklyWage is 1442.0, not 1442.307...
    double weeklyWage = salary / 52;
    double taxes = weeklyWage * INCOME_TAX_RATE;

    std::cout << "Yearly salary: " << formatMoney(salary) << std::endl;
    std::cout << "Weekly pay: " << formatMoney(weeklyWage) << std::endl;
    std::cout << "Taxes: " << formatMoney(taxes) << " at "
              << formatPercent(INCOME_TAX_RATE) << std::endl;

    return 0;
}
