#ifndef YOUDIDTHEWRONGTHINGEXCEPTION_H
#define YOUDIDTHEWRONGTHINGEXCEPTION_H

#include <stdexcept>
#include <string>

// A custom exception type.
// In Java this was "class YouDidTheWrongThingException extends RuntimeException".
// In C++ we derive from std::runtime_error and pass the message up to its
// constructor. The message is later read with e.what() (Java used getMessage()).
class YouDidTheWrongThingException : public std::runtime_error {
public:
    explicit YouDidTheWrongThingException(const std::string& message)
        : std::runtime_error("OOPS! You did the wrong thing : " + message) {}
};

#endif
