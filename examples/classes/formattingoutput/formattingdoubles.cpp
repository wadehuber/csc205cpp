#include <iostream>
#include <iomanip>
#include <locale>

// Custom number formatter to add comma separators
class comma_separator : public std::numpunct<char> {
protected:
    char do_thousands_sep() const override { return ','; }
    std::string do_grouping() const override { return "\003"; }
};

int main() {
    double number1 = 12.3456789;
    double number2 = 98.7654321;
    double number3 = 1234567890.555;
    double number4 = .0000000000000009;

    // Create locale with comma separator
    std::locale comma_locale(std::locale(), new comma_separator());

    std::cout << "No formatting: " << std::endl;
    std::cout << "  " << number1 << std::endl;
    std::cout << "  " << number2 << std::endl;
    std::cout << "  " << number3 << std::endl;
    std::cout << "  " << number4 << std::endl;

    std::cout << std::endl;
    std::cout << "fmt1 # - no decimal places: " << std::endl;
    std::cout << "  " << std::fixed << std::setprecision(0) 
              << number1 << std::endl;
    std::cout << "  " << number2 << std::endl;
    std::cout << "  " << number3 << std::endl;
    std::cout << "  " << number4 << std::endl;

    std::cout << std::endl;
    std::cout << "fmt2 #.## - 2 decimal places: " << std::endl;
    std::cout << "  " << std::fixed << std::setprecision(2) 
              << number1 << std::endl;
    std::cout << "  " << number2 << std::endl;
    std::cout << "  " << number3 << std::endl;
    std::cout << "  " << number4 << std::endl;

    std::cout << std::endl;
    std::cout << "fmt3 #,###.## - Comma-separated, 2 decimal places: " << std::endl;
    std::cout.imbue(comma_locale);
    std::cout << "  " << std::fixed << std::setprecision(2) 
              << number1 << std::endl;
    std::cout << "  " << number2 << std::endl;
    std::cout << "  " << number3 << std::endl;
    std::cout << "  " << number4 << std::endl;

    return 0;
}