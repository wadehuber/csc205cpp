#ifndef EMPTYCOLLECTIONEXCEPTION_H
#define EMPTYCOLLECTIONEXCEPTION_H

#include <stdexcept>
#include <string>

/**
 * Represents the situation in which a collection is empty.
 *
 * In Java this "extends RuntimeException". In C++ we derive from
 * std::runtime_error and pass the assembled message to its constructor.
 * Catch it with "catch (const EmptyCollectionException&)" and read the
 * message via what().
 *
 * @author Java Foundations
 * @version 4.0
 */
class EmptyCollectionException : public std::runtime_error {
public:
    /** Sets up this exception with an appropriate message. */
    EmptyCollectionException(const std::string& collection)
        : std::runtime_error("The " + collection + " is empty.") {}
};

#endif
