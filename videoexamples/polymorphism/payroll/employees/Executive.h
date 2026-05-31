#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <string>
#include "Employee.h"

//********************************************************************
//  Executive.h
//
//  Represents an executive staff member, who can earn a bonus.
//********************************************************************
class Executive : public Employee {
private:
    double bonus;

public:
    Executive(std::string eName, std::string eAddress, std::string ePhone,
              std::string socSecNumber, double rate);

    void awardBonus(double execBonus);

    double pay() override;
};

#endif
