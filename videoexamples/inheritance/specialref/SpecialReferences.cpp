#include <iostream>

#include "ParentClass.h"
#include "ChildClass.h"

int main() {
    ParentClass parentObject(1);
    ChildClass childObject(2);

    // Java prints an object by calling toString() automatically. In C++ we
    // call toString() ourselves and stream the resulting std::string.
    std::cout << "ParentClass object: " << parentObject.toString() << std::endl;
    std::cout << "ChildClass object: " << childObject.toString() << std::endl;
    std::cout << std::endl;

    childObject.setValues("TheParent", "TheChild", 4);
    std::cout << "ChildClass object: " << childObject.toString() << std::endl;

    return 0;
}
