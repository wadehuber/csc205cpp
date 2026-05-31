// RecursionWithStrings.cpp
//
// Examples of recursion with strings: reversing a string, checking whether a
// string contains a character, and drawing a square with '*' characters.
//
// Java String -> std::string.
//   str.length()        -> str.length()
//   str.charAt(0)       -> str[0]
//   str.substring(1)    -> str.substr(1)
//
// Java had overloaded printSquare (one-arg public, two-arg helper); C++
// overloads the same way.

#include <iostream>
#include <string>
#include <vector>

// Reverse a string
std::string reverseString(const std::string& str) {
    if (str.length() <= 1) {
        return str;
    }
    else {
        return (reverseString(str.substr(1)) + str[0]);
    }
}

// Check that a character exists in a string
bool contains(const std::string& str, char c) {
    if (str.length() < 1) {
        return false;
    }
    else if (str[0] == c) {
        return true;
    }
    else {
        return (contains(str.substr(1), c));
    }
}

// Recursion with a helper function
void printSquare(int side, int currentRow) {
    // Base case: if side < currentRow, do nothing
    if (currentRow <= side) {
        // Print a row
        for (int ii = 0; ii < side; ii++) {
            std::cout << "*";
        }
        std::cout << std::endl;
        printSquare(side, currentRow + 1);
    }
}
void printSquare(int side) {
    printSquare(side, 1);   // Start with row 1
}

int main() {
    std::vector<int> sideValues = {1, 3, 6};
    std::vector<std::string> strings = {"abcdefghijk", "CGCC", "Java"};

    std::cout << "reverseString:" << std::endl;
    for (const std::string& s : strings) {
        std::cout << "  String " << s << " reversed: " << reverseString(s) << std::endl;
    }
    std::cout << std::endl;

    std::cout << "contains:" << std::endl;
    for (const std::string& s : strings) {
        // Java printed the boolean as "true"/"false"; std::boolalpha does the same.
        std::cout << "  Does string " << s << " contain 'a'? "
                  << std::boolalpha << contains(s, 'a') << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Squares:" << std::endl;
    for (int val : sideValues) {
        std::cout << "Square of size " << val << ":" << std::endl;
        printSquare(val);
        std::cout << std::endl;
    }

    return 0;
}
