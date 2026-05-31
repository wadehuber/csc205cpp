#include "Cat.h"
#include <iostream>

// super(name) in Java becomes the base initializer list ": Animal(name)".
Cat::Cat(std::string name) : Animal(name) {
}

void Cat::speak() {
    std::cout << "Meow." << std::endl;
}
