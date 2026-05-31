#include "Bat.h"
#include <iostream>

Bat::Bat(std::string name) : Animal(name) {
}

void Bat::speak() {
    std::cout << "<sonar>" << std::endl;
}

void Bat::move() {
    fly();
}

void Bat::fly() {
    std::cout << "FlapFlapFlapFlap" << std::endl;
}
