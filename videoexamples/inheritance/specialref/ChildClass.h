#ifndef CHILDCLASS_H
#define CHILDCLASS_H

#include <string>
#include "ParentClass.h"

class ChildClass : public ParentClass {
private:
    // Shadow data member - USE CAUTION. ChildClass::myName shadows (hides)
    // ParentClass::myName; both objects exist. Same idea as the Java example.
    std::string myName;

public:
    ChildClass(int num);

    void setValues(std::string pName, std::string cName, int num);

    std::string toString() const override;
};

#endif
