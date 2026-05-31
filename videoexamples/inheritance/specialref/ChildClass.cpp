#include "ChildClass.h"

// super(num*10) becomes the base initializer list ": ParentClass(num*10)".
ChildClass::ChildClass(int num) : ParentClass(num * 10) {
    myName = "ChildClass";
    // 'this->num' is the inherited ParentClass::num (it is not shadowed).
    this->num = num;
}

void ChildClass::setValues(std::string pName, std::string cName, int num) {
    // super.myName in Java -> qualify with the base class name to reach the
    // shadowed parent member: ParentClass::myName.
    ParentClass::myName = pName;
    this->myName = cName;       // Don't strictly need 'this->' here
    num = num * 2;              // This is num the parameter
    this->num = num;            // Must use 'this->' to reach the member
}

std::string ChildClass::toString() const {
    // super.toString() in Java -> ParentClass::toString().
    return ParentClass::toString() + " --> ChildClass [myName=" + myName +
           ", num=" + std::to_string(num) + "]";
}
