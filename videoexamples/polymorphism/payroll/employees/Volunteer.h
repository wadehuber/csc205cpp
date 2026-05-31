#ifndef VOLUNTEER_H
#define VOLUNTEER_H

#include <string>
#include "StaffMember.h"

//********************************************************************
//  Volunteer.h
//
//  Represents a staff member that works as a volunteer.
//********************************************************************
class Volunteer : public StaffMember {
public:
    Volunteer(std::string eName, std::string eAddress, std::string ePhone);

    double pay() override;
};

#endif
