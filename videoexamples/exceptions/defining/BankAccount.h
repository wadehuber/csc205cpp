#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

// A simple bank account that can throw InsufficientFundsException.
// In Java this was the BankAccount class (which also held main()).
//
// In Java, withdraw declared "throws InsufficientFundsException". C++ has no
// equivalent checked-exception declaration; any function may throw, so we
// just throw inside the function body (see BankAccount.cpp).
class BankAccount {
public:
    // public here just so main() can set it directly, as the Java did.
    double balance = 0.0;

    void withdraw(double amount);
};

#endif
