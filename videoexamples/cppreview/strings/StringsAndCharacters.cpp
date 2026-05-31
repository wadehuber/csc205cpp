// StringsAndCharacters.cpp
// C++ version of StringsAndCharacters.java
//
// Java review topic: looping over characters and splitting strings.
//   for (Character c : s.toCharArray()) -> range-based for over a std::string
//   Character.isLetter(c)               -> std::isalpha((unsigned char) c)
//   s.split(" ")                        -> our own split() helper

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

// Same split helper as in String205 (kept local so this file stands alone).
std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        result.push_back(item);
    }
    return result;
}

void onlyChars(const std::string& s) {
    std::string result = "";
    std::cout << "Before: " << s << std::endl;
    for (char c : s) {
        if (std::isalpha((unsigned char) c)) {
            result += c;
        }
    }
    std::cout << "After: " << result << std::endl;
}

void printShortWords(int len, const std::string& s) {
    std::vector<std::string> words = split(s, ' ');
    std::cout << "Original (len=" << len << "): " << s << std::endl;

    std::cout << "Final (len=" << len << "): ";
    for (const std::string& k : words) {
        if ((int) k.length() <= len) {
            std::cout << k << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    onlyChars("This is a test for csc 205 class");
    onlyChars("ABCD1234abcd%^&*(qrst{}|XYZ");
    printShortWords(5, "The great enemy of clear language is insincerity.");
    printShortWords(3, "The great enemy of clear language is insincerity.");

    return 0;
}
