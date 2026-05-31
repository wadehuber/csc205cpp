#include "Dog.h"
#include <iostream>

Dog::Dog(std::string name) : Animal(name) {
}

void Dog::speak() {
    std::cout << "Woof! Woof!" << std::endl;
}

void Dog::move() {
    std::cout << name << " is running!" << std::endl;
}

void Dog::fetch() {
    std::cout << "Ball! Ball!" << std::endl;
}
