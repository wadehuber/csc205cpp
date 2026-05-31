#include "Bear.h"
#include <iostream>

Bear::Bear(std::string name) : Animal(name) {
}

void Bear::speak() {
    std::cout << "Growl! ROAR!" << std::endl;
}

void Bear::attack() {
    std::cout << "Yum, breakfast!" << std::endl;
}

void Bear::receiveHit(int x) {
    if (x <= 10) {
        std::cout << "Humph?!?!" << std::endl;
    } else {
        std::cout << "What was that?" << std::endl;
    }
}
