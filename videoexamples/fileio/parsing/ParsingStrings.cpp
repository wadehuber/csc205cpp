// ParsingStrings.cpp
//
// Java used String.split(regex) and Scanner to break strings into pieces.
// C++ has NO String.split, so we write small helper functions:
//   * split(s, delim)        splits on a single character (like split(" "))
//   * splitWhitespace(s)     splits on runs of whitespace (like a Scanner)
//   * splitAny(s, delims)    splits on ANY of several characters
//                            (like Scanner.useDelimiter("[,;|\\n]"))

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

// Split on a single delimiter character (mirrors Java's split(" ")).
// Like Java's split, a delimiter that never appears yields one element:
// the whole string.
std::vector<std::string> split(const std::string& s, char delim) {
    std::vector<std::string> result;
    std::istringstream stream(s);
    std::string token;
    while (std::getline(stream, token, delim)) {
        result.push_back(token);
    }
    return result;
}

// Split on runs of whitespace, skipping empty tokens (like a Scanner does
// when reading whitespace-separated words with next()).
std::vector<std::string> splitWhitespace(const std::string& s) {
    std::vector<std::string> result;
    std::istringstream stream(s);
    std::string token;
    while (stream >> token) {   // ">>" skips whitespace automatically
        result.push_back(token);
    }
    return result;
}

// Split on ANY of the characters in 'delims' (like Scanner's "[,;|\\n]").
std::vector<std::string> splitAny(const std::string& s, const std::string& delims) {
    std::vector<std::string> result;
    std::string token;
    for (char c : s) {
        if (delims.find(c) != std::string::npos) {
            if (!token.empty()) {
                result.push_back(token);
                token.clear();
            }
        } else {
            token += c;
        }
    }
    if (!token.empty()) {
        result.push_back(token);
    }
    return result;
}

int main() {
    // Example string containing space-separated values
    std::string spaceString = "The distance is nothing when one has a motive.";

    // Example string containing comma-separated values
    std::string csvString = "Yoda,Chewbacca,Jabba,Mando";

    // Example string containing mixed delimiters
    std::string multiDelimString = "1,20;333|4040\n55555";

    std::cout << "Parsing a space-delimited string:" << std::endl;
    std::cout << "Using split():" << std::endl;
    std::vector<std::string> words = split(spaceString, ' ');
    for (const std::string& word : words) {
        std::cout << "    " << word << std::endl;
    }

    std::cout << "\nUsing Scanner:" << std::endl;
    // C++ has no Scanner; splitWhitespace() does the same whitespace tokenizing.
    for (const std::string& word : splitWhitespace(spaceString)) {
        std::cout << "    " << word << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Parsing a comma-delimited string using split():" << std::endl;
    // NOTE: matching the Java exactly, this splits on a SPACE, not a comma.
    // Since csvString has no spaces, the result is the whole string as one piece.
    std::vector<std::string> swcharacters = split(csvString, ' ');
    for (const std::string& swcharacter : swcharacters) {
        std::cout << "    " << swcharacter << std::endl;
    }

    // More complex example showing splitting on multiple delimiters
    std::cout << "\nScanner with multiple delimiters:" << std::endl;
    for (const std::string& part : splitAny(multiDelimString, ",;|\n")) {
        std::cout << part << std::endl;
    }

    return 0;
}
