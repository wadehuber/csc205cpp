// ParsingWithScanner.cpp
//
// Java read studentgrades.txt line by line, then used a Scanner with a comma
// delimiter to pull a name and three exam scores out of each line.
//
// In C++ we read each line with std::getline, then split the line on commas
// with a small helper. We convert the score strings to ints with std::stoi
// (Java used Scanner.nextInt() / Integer.parseInt).

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

// Split on a single delimiter character (C++ has no String.split).
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
    // Run this program from the parsing directory so it finds the data file.
    std::ifstream reader("studentgrades.txt");
    if (!reader) {
        std::cerr << "Could not open studentgrades.txt" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(reader, line)) {
        std::vector<std::string> tokens = split(line, ',');

        std::string name = tokens[0];
        int exam1 = std::stoi(tokens[1]);   // string -> int (like Integer.parseInt)
        int exam2 = std::stoi(tokens[2]);
        int exam3 = std::stoi(tokens[3]);

        double avg = (exam1 + exam2 + exam3) / 3.0;

        // At this point all the data is separated into variables & we can use
        // the variables as needed.
        std::cout << "Student: " << name << "    Exam Average: " << avg << std::endl;
    }

    return 0;
}
