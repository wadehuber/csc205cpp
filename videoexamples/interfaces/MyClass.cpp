#include "MyClass.h"
#include <iostream>

MyClass::MyClass() {
    // Auto-generated constructor stub
}

int MyClass::add(int num) {
    return num + MYNUM;
}

void MyClass::greet(std::string name) {
    std::cout << "Hello, " << name << std::endl;
}
