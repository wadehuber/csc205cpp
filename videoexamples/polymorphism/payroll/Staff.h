#ifndef STAFF_H
#define STAFF_H

#include <vector>
#include "employees/StaffMember.h"
#include "employees/Executive.h"
#include "employees/Employee.h"
#include "employees/Hourly.h"
#include "employees/Volunteer.h"

//********************************************************************
//  Staff.h
//
//  Represents the personnel staff of a particular business.
//********************************************************************
class Staff {
private:
    // Java held a "StaffMember[]". Here the concrete employee objects live
    // as named members (so no new/delete), and staffList holds StaffMember*
    // pointers to them. Calls through those pointers are polymorphic.
    Executive tony;
    Employee paulie;
    Employee vito;
    Hourly michael;
    Volunteer adrianna;
    Volunteer benny;

    std::vector<StaffMember*> staffList;

public:
    Staff();

    // Pays all staff members.
    void payday();
};

#endif
