#ifndef ELEMENTNOTFOUNDEXCEPTION_H
#define ELEMENTNOTFOUNDEXCEPTION_H

#include <stdexcept>
#include <string>

// ElementNotFoundException represents the situation in which a target element
// is not present in a collection.
//
// In Java this "extends RuntimeException". In C++ we derive from
// std::runtime_error and pass the assembled message to its constructor.
// Read the message with e.what() (Java used getMessage()).
class ElementNotFoundException : public std::runtime_error {
public:
    ElementNotFoundException(const std::string& collection)
        : std::runtime_error("The target element is not in this " + collection) {}
};

#endif
