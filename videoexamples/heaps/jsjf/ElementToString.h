#ifndef ELEMENTTOSTRING_H
#define ELEMENTTOSTRING_H

#include <string>
#include <sstream>
#include <type_traits>

// Small helper used by the trees' toString() methods.
//
// In Java, every element was an Object, so the code could call
// element.toString() (Integer, StudentRecord, etc. all have one). In C++ a
// primitive like int has no .toString(), so we branch at compile time:
//   - arithmetic types (int, double, ...) are streamed with operator<<
//   - everything else is expected to provide a .toString() method
// This lets the same generic tree print both LinkedHeap<int> and
// LinkedHeap<StudentRecord> exactly as the Java version did.
template <typename T>
std::string elementToString(const T& element) {
    if constexpr (std::is_arithmetic_v<T>) {
        std::ostringstream out;
        out << element;
        return out.str();
    } else {
        return element.toString();
    }
}

#endif
