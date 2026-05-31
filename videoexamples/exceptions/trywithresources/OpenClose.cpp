#include <iostream>
#include "OpenClose.h"

OpenClose::OpenClose(const std::string& l) : label(l) {
    std::cout << "   Opening : " << label << std::endl;
}

// The destructor is the C++ stand-in for Java's AutoCloseable.close().
// It runs automatically when the object leaves scope. We call close() from
// here so the "Closing" message prints exactly once (the guard prevents a
// double-close if close() was already called by hand).
OpenClose::~OpenClose() {
    close();
}

void OpenClose::close() {
    if (!closed) {
        std::cout << "   Closing : " << label << std::endl;
        closed = true;
    }
}
