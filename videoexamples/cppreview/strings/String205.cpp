// String205.cpp
// C++ version of String205.java (definitions).

#include "String205.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

// Java's String.split has no direct std::string equivalent, so we write one.
// This splits on a single character delimiter, like s.split(" ").
std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        result.push_back(item);
    }
    return result;
}

// Character.isLetter(c) -> std::isalpha. charAt(ii) -> s[ii].
std::string justLetters(const std::string& s) {
    std::string ret = "";

    for (int ii = 0; ii < (int) s.length(); ii++) {
        if (std::isalpha((unsigned char) s[ii])) {
            ret += s[ii];
        }
    }

    return ret;
}

// Range-based for over a std::string is the equivalent of Java's
// for (char c : s.toCharArray()).
std::string noVowels(const std::string& s) {
    std::string ret = "";

    for (char c : s) {
        if (!isVowel(c)) {
            ret += c;
        }
    }

    return ret;
}

bool isVowel(char c) {
    bool ret = false;

    // Character.toLowerCase(c) -> std::tolower((unsigned char) c)
    switch (std::tolower((unsigned char) c)) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            ret = true;
    }
    return ret;
}

void individualWords(const std::string& s) {
    std::vector<std::string> words = split(s, ' ');
    for (int ii = 0; ii < (int) words.size(); ii++) {
        std::cout << "[(" << ii << ")" << words[ii] << "] ";
    }
    std::cout << std::endl;
}
