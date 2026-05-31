#include "Boxer.h"
#include <iostream>

Boxer::Boxer(std::string name) {
    this->name = name;
}

void Boxer::attack() {
    std::cout << name << " stings like a bee" << std::endl;
}

void Boxer::receiveHit(int x) {
    if (x <= 5) {
        std::cout << name << " floats like a bee" << std::endl;
    } else {
        std::cout << name << " staggers againts the ropes!!!" << std::endl;
    }
}

std::string Boxer::toString() const {
    return "Boxer [name=" + name + "]";
}
