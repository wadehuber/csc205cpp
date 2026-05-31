#include "MyOtherClass.h"
#include <iostream>

MyOtherClass::MyOtherClass() {
    // Auto-generated constructor stub
}

void MyOtherClass::hello() {
    std::cout << "Hello, world" << std::endl;
}

int MyOtherClass::add(int num) {
    return num + 1;
}

void MyOtherClass::greet(std::string name) {
    std::cout << "Hello, " << name << ".  The secret number is " << MYNUM << "." << std::endl;
}
