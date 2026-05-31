#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H

#include <string>

//********************************************************************
//  StaffMember.h
//
//  Represents a generic staff member. (Java: abstract class)
//********************************************************************
class StaffMember {
protected:
    std::string name;
    std::string address;
    std::string phone;

public:
    StaffMember(std::string eName, std::string eAddress, std::string ePhone);

    // Polymorphic base classes need a virtual destructor in C++.
    virtual ~StaffMember() = default;

    // toString() is overridden by subclasses, so it must be virtual.
    virtual std::string toString() const;

    // Java's "public abstract double pay();" -> pure virtual ("= 0").
    virtual double pay() = 0;
};

#endif
