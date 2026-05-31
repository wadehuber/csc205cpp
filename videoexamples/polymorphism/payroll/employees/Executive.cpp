#include "Executive.h"

Executive::Executive(std::string eName, std::string eAddress, std::string ePhone,
                     std::string socSecNumber, double rate)
    : Employee(eName, eAddress, ePhone, socSecNumber, rate) {
    bonus = 0;  // bonus has yet to be awarded
}

void Executive::awardBonus(double execBonus) {
    bonus = execBonus;
}

double Executive::pay() {
    // super.pay() -> Employee::pay()
    double payment = Employee::pay() + bonus;

    bonus = 0;

    return payment;
}
