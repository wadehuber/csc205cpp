#ifndef NONCOMPARABLEELEMENTEXCEPTION_H
#define NONCOMPARABLEELEMENTEXCEPTION_H

#include <stdexcept>
#include <string>

// NonComparableElementException represents the situation in which an attempt
// is made to add an element that is not comparable to an ordered collection.
//
// In Java this "extends RuntimeException". In C++ we derive from
// std::runtime_error and pass the assembled message to its constructor.
//
// NOTE: In Java, ArrayOrderedList checks "element instanceof Comparable" and
// throws this. In C++ comparability is duck-typed (the element type must
// provide operator<), so the check happens at compile time rather than at
// run time. We keep this class for fidelity to the Java lesson.
class NonComparableElementException : public std::runtime_error {
public:
    NonComparableElementException(const std::string& collection)
        : std::runtime_error("The " + collection + " requires Comparable elements.") {}
};

#endif
