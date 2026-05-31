#include "Employee.h"

Employee::Employee(std::string eName, std::string eAddress, std::string ePhone,
                   std::string socSecNumber, double rate)
    : StaffMember(eName, eAddress, ePhone) {
    socialSecurityNumber = socSecNumber;
    payRate = rate;
}

std::string Employee::toString() const {
    // super.toString() -> StaffMember::toString()
    std::string result = StaffMember::toString();

    result += "\nSocial Security Number: " + socialSecurityNumber;

    return result;
}

double Employee::pay() {
    return payRate;
}
