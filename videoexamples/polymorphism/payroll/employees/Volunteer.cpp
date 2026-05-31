#include "Volunteer.h"

Volunteer::Volunteer(std::string eName, std::string eAddress, std::string ePhone)
    : StaffMember(eName, eAddress, ePhone) {
}

double Volunteer::pay() {
    return 0.0;
}
