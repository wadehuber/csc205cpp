#include "Cat.h"
#include <iostream>

Cat::Cat(std::string name) : Animal(name) {
}

void Cat::speak() {
    std::cout << "Meow." << std::endl;
}
