#include "Eagle.h"
#include <iostream>

Eagle::Eagle(std::string name) : Animal(name) {
}

void Eagle::speak() {
    std::cout << "Shriek!!!" << std::endl;
}

void Eagle::move() {
    fly();
}

void Eagle::fly() {
    std::cout << "Soaring!" << std::endl;
}
