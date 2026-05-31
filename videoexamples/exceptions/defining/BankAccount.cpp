#include <iostream>
#include <string>
#include "BankAccount.h"
#include "InsufficientFundsException.h"

// Example of defining and using a custom exception with an extra field.
// In Java this was BankAccount (class + main together).

void BankAccount::withdraw(double amount) {
    if (amount > balance) {
        std::string msg = "Not enough money! You need "
            + std::to_string(amount - balance) + " more dollars";
        // throw by VALUE (Java was "throw new ...").
        throw InsufficientFundsException(msg, amount);
    }
    balance -= amount;
}

int main() {
    BankAccount account;
    account.balance = 100.0;

    try {
        account.withdraw(150.0);
    }
    catch (const InsufficientFundsException& e) {
        // Java used e.getMessage(); in C++ the message is e.what().
        std::cerr << e.what() << ". Needed: $" << e.getAmount() << std::endl;
    }

    return 0;
}
