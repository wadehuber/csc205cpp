#include "Animal.h"
#include <iostream>

Animal::Animal(std::string name) {
    this->name = name;
}

void Animal::move() {
    std::cout << name << " is moving like an animal" << std::endl;
}

std::string Animal::getName() const {
    return this->name;
}

void Animal::setName(std::string n) {
    this->name = n;
}

std::string Animal::toString() const {
    return "[name=" + name + "]";
}
