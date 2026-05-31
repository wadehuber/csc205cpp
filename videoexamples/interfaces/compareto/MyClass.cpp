#include "MyClass.h"

MyClass::MyClass(int num, std::string name) {
    this->num = num;
    this->name = name;
}

std::string MyClass::toString() const {
    return "[" + std::to_string(num) + ", " + name + "]";
}

int MyClass::compareTo(const MyClass& o) const {
    // return this->name.compare(o.name);
    return this->num - o.num;
}
