// FileIOExample.cpp
//
// Java original created a file, wrote a line to it, then read it back.
// In C++ we use std::ofstream to write and std::ifstream to read.
//
// Java checked for problems with try/catch (IOException). The simple C++
// idiom is to ASK the stream whether it opened: "if (!stream) { ... }".
// (We do NOT use C++ exceptions for opening files.)

#include <iostream>
#include <fstream>   // std::ofstream (writing) and std::ifstream (reading)
#include <string>

int main() {
    std::string fileName = "example.txt";

    // In Java a File object was created and file.createNewFile() was called.
    // In C++ simply opening an ofstream creates the file, so there is no
    // separate "create" step.
    std::cout << "Creating new file ..." << std::endl;

    std::cout << "Writing to file ..." << std::endl;
    {
        // Opening this ofstream creates/opens example.txt for writing.
        std::ofstream fw(fileName);
        if (!fw) {
            std::cerr << "Something went wrong while writing the file" << std::endl;
        } else {
            fw << "This is a test for CSC205\n";
            // The stream is flushed and closed automatically when it goes
            // out of scope here (like Java's try-with-resources finally block).
        }
    }
    std::cout << "Done!" << std::endl;

    std::cout << std::endl;
    std::cout << "Reading from file ..." << std::endl;
    {
        std::ifstream fr(fileName);
        if (!fr) {
            std::cerr << "Something went wrong while reading the file" << std::endl;
        } else {
            // Java read raw characters into a char[]; here we read the whole
            // contents into a std::string, which is the simple C++ way.
            std::string contents;
            std::getline(fr, contents);
            std::cout << "Contents of the file: " << contents << std::endl;
        }
    }
    std::cout << "Done!" << std::endl;

    return 0;
}
