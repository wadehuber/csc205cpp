// TextFileReader.cpp
//
// Java used BufferedReader + readLine() to read a text file line by line.
// In C++ we open a std::ifstream and read each line with std::getline.
//
// Java caught IOException; the simple C++ idiom is "if (!stream)" to test
// whether the file opened.

#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Run this program from the bufferedio directory so it finds input.txt.
    std::ifstream reader("input.txt");
    if (!reader) {
        std::cerr << "Could not open input.txt" << std::endl;
        return 1;
    }

    std::string line;
    // getline returns the stream; when it reaches end-of-file the loop stops.
    // This is the C++ equivalent of "while ((line = reader.readLine()) != null)".
    while (std::getline(reader, line)) {
        std::cout << line << std::endl;
    }

    return 0;
}
