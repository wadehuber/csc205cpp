#include "SugarGlider.h"
#include <iostream>

SugarGlider::SugarGlider(std::string name) : Animal(name) {
}

void SugarGlider::speak() {
    std::cout << "I'm a sugar glider!" << std::endl;
}
