#ifndef EMPTYCOLLECTIONEXCEPTION_H
#define EMPTYCOLLECTIONEXCEPTION_H

#include <stdexcept>
#include <string>

// Represents the situation in which a collection is empty.
//
// In Java this "extends RuntimeException". In C++ we derive from
// std::runtime_error and pass the assembled message to its constructor.
class EmptyCollectionException : public std::runtime_error {
public:
    EmptyCollectionException(const std::string& collection)
        : std::runtime_error("The " + collection + " is empty.") {}
};

#endif
