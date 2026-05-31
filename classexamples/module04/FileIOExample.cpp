#include <iostream>
#include <fstream>   // std::ofstream is C++'s file-writing tool (like Java's PrintWriter)
#include <string>

int main() {

    // The file is created in the current directory (run this from module04).
    std::string fileName = "myfile.txt";

    // Opening the stream tries to create/open the file for writing.
    std::ofstream writer(fileName);

    // Java used try/catch to handle a file that couldn't be opened.
    // In C++, the simple way is to ASK the stream whether it opened.
    // "if (!writer)" is true when the file could not be opened.
    if (!writer) {
        std::cout << "Output file not found: " << fileName << std::endl;
    } else {
        // The "<<" operator writes to the file, similar to writing to cout.
        writer << "I'm writing to this file" << std::endl;
        for (int ii = 0; ii < 10; ii++) {
            writer << ii << " ";
        }
        writer << std::endl;
        writer << "That's all folks!" << std::endl;
    }

    // Like Java's "finally": this always happens.
    // close() is safe to call even if the file never opened. (The stream
    // would also close itself automatically when it goes out of scope.)
    writer.close();
    std::cout << "All done" << std::endl;

    return 0;
}
