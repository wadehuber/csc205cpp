#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "StaffMember.h"

//********************************************************************
//  Employee.h
//
//  Represents a general paid employee. (Java: extends StaffMember)
//********************************************************************
class Employee : public StaffMember {
protected:
    std::string socialSecurityNumber;
    double payRate;

public:
    Employee(std::string eName, std::string eAddress, std::string ePhone,
             std::string socSecNumber, double rate);

    std::string toString() const override;

    double pay() override;
};

#endif
