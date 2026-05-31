#ifndef INSUFFICIENTFUNDSEXCEPTION_H
#define INSUFFICIENTFUNDSEXCEPTION_H

#include <stdexcept>
#include <string>

// A custom exception that carries an extra field (the amount).
// In Java this was "class InsufficientFundsException extends Exception"
// with a private double amount and a getAmount() getter.
//
// In C++ we derive from std::runtime_error, pass the message to its
// constructor, and keep the extra field ourselves. The message is read
// with e.what() (Java used getMessage()).
class InsufficientFundsException : public std::runtime_error {
private:
    double amount;

public:
    InsufficientFundsException(const std::string& message, double amount)
        : std::runtime_error(message), amount(amount) {}

    double getAmount() const {
        return amount;
    }
};

#endif
