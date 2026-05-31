// TextFileWriter.cpp
//
// Java used BufferedWriter + FileWriter to write lines to a text file.
// In C++ we open a std::ofstream and write with the "<<" operator.

#include <iostream>
#include <fstream>

int main() {
    // Run this program from the bufferedio directory; it creates output.txt.
    std::ofstream writer("output.txt");
    if (!writer) {
        std::cerr << "Could not open output.txt for writing" << std::endl;
        return 1;
    }

    writer << "First line\n";
    writer << "Second line\n";
    // The stream closes automatically when it goes out of scope, but Java
    // called close() explicitly, so we do too for a 1-1 match.
    writer.close();

    return 0;
}
