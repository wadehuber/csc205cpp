#include "StaffMember.h"

StaffMember::StaffMember(std::string eName, std::string eAddress,
                         std::string ePhone) {
    name = eName;
    address = eAddress;
    phone = ePhone;
}

std::string StaffMember::toString() const {
    std::string result = "Name: " + name + "\n";

    result += "Address: " + address + "\n";
    result += "Phone: " + phone;

    return result;
}
