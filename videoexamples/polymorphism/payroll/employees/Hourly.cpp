#include "Hourly.h"

Hourly::Hourly(std::string eName, std::string eAddress, std::string ePhone,
               std::string socSecNumber, double rate)
    : Employee(eName, eAddress, ePhone, socSecNumber, rate) {
    hoursWorked = 0;
}

void Hourly::addHours(int moreHours) {
    hoursWorked += moreHours;
}

double Hourly::pay() {
    double payment = payRate * hoursWorked;

    hoursWorked = 0;

    return payment;
}

std::string Hourly::toString() const {
    // super.toString() -> Employee::toString()
    std::string result = Employee::toString();

    result += "\nCurrent hours: " + std::to_string(hoursWorked);

    return result;
}
