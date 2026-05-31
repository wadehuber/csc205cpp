#ifndef NONCOMPARABLEELEMENTEXCEPTION_H
#define NONCOMPARABLEELEMENTEXCEPTION_H

#include <stdexcept>
#include <string>

// NonComparableElementException represents the situation in which an attempt
// is made to add an element that is not comparable to an ordered collection.
//
// In Java this "extends RuntimeException". In C++ we derive from
// std::runtime_error and pass the assembled message up to its constructor.
//
// NOTE: In the Java code this was thrown after an "instanceof Comparable"
// check. C++ templates are duck-typed, so there is no runtime type check; if
// a type does not define operator< the program simply will not compile. We
// keep the class for fidelity, but it is effectively never thrown in C++.
class NonComparableElementException : public std::runtime_error {
public:
    NonComparableElementException(const std::string& collection)
        : std::runtime_error("The " + collection + " requires Comparable elements.") {}
};

#endif
