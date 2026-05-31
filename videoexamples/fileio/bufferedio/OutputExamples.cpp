// OutputExamples.cpp
//
// Java showed System.out.println / print / printf.
// In C++ the idiomatic equivalent is std::cout with the "<<" operator.
// For formatting (like printf's %.2f or %5d) we use manipulators from
// <iomanip> (std::fixed, std::setprecision, std::setw).

#include <iostream>
#include <iomanip>

int main() {
    // Basic output
    std::cout << "Hello, World!" << std::endl;   // println adds a newline
    std::cout << "No line break";                // print, no newline
    std::cout << "Formatted: " << 42 << std::endl;

    // Formatting examples
    // %.2f -> std::fixed with setprecision(2)
    std::cout << "Float: " << std::fixed << std::setprecision(2) << 3.14159 << std::endl;
    // %5d -> right-justified in a field 5 wide (setw)
    std::cout << "Add padding: " << std::setw(5) << 42 << std::endl;

    return 0;
}
