// Cat.cpp
// C++ version of Cat.java (implementation).

#include "Cat.h"
#include <iostream>

Cat::Cat() : name("") {}

Cat::Cat(std::string name) : name(name) {}

void Cat::speak() {
    std::cout << "Meow" << std::endl;
}

std::string Cat::toString() const {
    return "My name is " + name;
}

std::ostream& operator<<(std::ostream& os, const Cat& cat) {
    os << cat.toString();
    return os;
}
