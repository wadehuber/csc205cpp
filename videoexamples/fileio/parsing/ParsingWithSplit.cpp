// ParsingWithSplit.cpp
//
// Java used String.split(" ") to break a phrase into words.
// C++ has no String.split, so we write a small split() helper and use
// .size() where Java used the array's .length.

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// Split on a single delimiter character (mirrors Java's split(" ")).
std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> result;
    std::istringstream stream(s);
    std::string token;
    while (std::getline(stream, token, delim)) {
        result.push_back(token);
    }
    return result;
}

int main() {
    std::string phrase = "Grace Hopper wrote the first compiler";

    // create a vector of strings called words.
    //   each element will contain one of the words in phrase
    std::vector<std::string> words = split(phrase, ' ');   // space is the delimiter

    std::cout << "The phrase has been parsed into " << words.size() << " words." << std::endl;

    for (const std::string& word : words) {
        std::cout << word << std::endl;
    }

    return 0;
}
