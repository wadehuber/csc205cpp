#include "ParentClass.h"

ParentClass::ParentClass(int num) {
    this->num = num;
    myName = "ParentClass";
}

std::string ParentClass::toString() const {
    return "ParentClass [myName=" + myName + ", num=" + std::to_string(num) + "]";
}
