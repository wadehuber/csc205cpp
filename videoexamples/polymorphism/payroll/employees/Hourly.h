#ifndef HOURLY_H
#define HOURLY_H

#include <string>
#include "Employee.h"

//********************************************************************
//  Hourly.h
//
//  Represents an employee that gets paid by the hour.
//********************************************************************
class Hourly : public Employee {
private:
    int hoursWorked;

public:
    Hourly(std::string eName, std::string eAddress, std::string ePhone,
           std::string socSecNumber, double rate);

    void addHours(int moreHours);

    double pay() override;

    std::string toString() const override;
};

#endif
