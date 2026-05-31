// Sentences.cpp
// C++ version of Sentences.java
//
// NOTE: In the Java original, main() declared a "people" array but never used
// it, and the onlyChars / printShortWords helpers were never called -- main
// did nothing observable. We keep the same structure here. The helpers are
// defined (and demonstrate the same string techniques as StringsAndCharacters)
// but, like Java, main does not call them.
//
// Java review topic recap:
//   s.toCharArray() loop  -> range-based for over std::string
//   Character.isLetter(c) -> std::isalpha((unsigned char) c)
//   s.split(" ")          -> split() helper

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

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
    std::cout << "Original (len=" << len << ": " << s << std::endl;

    std::cout << "Final (len=" << len << ": ";
    for (const std::string& k : words) {
        if ((int) k.length() <= len) {
            std::cout << k << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    // Like the Java original, this array is declared but unused. We comment it
    // out so the compiler does not warn about an unused variable under -Wall.
    // std::vector<std::string> people = {
    //     "Anthony Howard Stark",
    //     "Mary Jane Watson",
    //     "Harry James Potter",
    //     "Bill S. Preston",
    //     "Amy Farrah Fowler",
    //     "Gandalf the Grey"
    // };

    return 0;
}
