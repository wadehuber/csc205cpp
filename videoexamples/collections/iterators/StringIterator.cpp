// StringIterator.cpp
// C++ version of StringIterator.java.
//
// In Java this used s.toCharArray() and a for-each loop. A C++ std::string is
// already a sequence of characters, so a range-based for loop walks it
// directly -- no conversion needed.
//
// Character.toUpperCase(c)  ->  std::toupper((unsigned char) c)  from <cctype>.
// (We cast to unsigned char because std::toupper misbehaves on negative chars.)

#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string s = "Hello, world!";

    for (char c : s) {
        char upper = (char) std::toupper((unsigned char) c);
        std::cout << "[" << upper << "]" << std::endl;
    }

    return 0;
}
