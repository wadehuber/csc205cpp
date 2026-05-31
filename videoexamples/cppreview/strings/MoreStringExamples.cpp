// MoreStringExamples.cpp
// C++ version of MoreStringExamples.java
//
// Java review topic: more std::string operations.
//   s.toLowerCase() / s.toUpperCase() -> no single method in C++; we loop and
//        apply std::tolower / std::toupper (from <cctype>) to each char.
//   s.substring(a)    -> s.substr(a)            (to end of string)
//   s.substring(a, b) -> s.substr(a, b - a)     (C++ takes a LENGTH, not end index!)
//   s.concat(t)       -> s + t                  (the + operator joins strings)

#include <iostream>
#include <string>
#include <cctype>

// Helpers, since C++ std::string has no built-in toLowerCase/toUpperCase.
std::string toLower(std::string s) {
    for (char& c : s) c = (char) std::tolower((unsigned char) c);
    return s;
}
std::string toUpper(std::string s) {
    for (char& c : s) c = (char) std::toupper((unsigned char) c);
    return s;
}

int main() {
    std::string s1 = "More String examples";
    std::string s2 = "abcd123ABCD";

    std::cout << "S1: " << s1 << std::endl;
    std::cout << "S2: " << s2 << std::endl;

    std::cout << std::endl;
    std::cout << "Change case:" << std::endl;
    std::cout << "  " << toLower(s1) << std::endl;
    std::cout << "  " << toLower(s2) << std::endl;
    std::cout << "  " << toLower("This is a string literal") << std::endl;
    std::cout << "  " << toUpper(s1) << std::endl;
    std::cout << "  " << toUpper(s2) << std::endl;
    std::cout << "  " << toUpper("This is a string literal") << std::endl;

    std::cout << std::endl;
    std::cout << "Getting sub-strings:" << std::endl;
    // substring(3) -> substr(3)
    std::cout << "  " << s1.substr(3) << std::endl;
    std::cout << "  " << s2.substr(3) << std::endl;
    std::cout << "  " << std::string("This is a string literal").substr(3) << std::endl;
    // substring(3,8) -> substr(3, 8-3); substring(4,7) -> substr(4, 7-4); etc.
    std::cout << "  " << s1.substr(3, 8 - 3) << std::endl;
    std::cout << "  " << s2.substr(4, 7 - 4) << std::endl;
    std::cout << "  " << std::string("This is a string literal").substr(10, 16 - 10) << std::endl;

    std::cout << std::endl;
    std::cout << "Concatenating strings:" << std::endl;
    // concat -> the + operator
    std::cout << "  " << s1 + s2 << std::endl;
    std::cout << "  " << s2 + s1 << std::endl;
    std::cout << "  " << std::string("This program has ") + s1 << std::endl;

    return 0;
}
