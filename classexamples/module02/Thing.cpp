#include "Thing.h"
#include <iostream>

// In Java this was: this.id = id; (plus an implicit super())
Thing::Thing(int id) {
    this->id = id;
    std::cout << "THING " << id << ": Constructor" << std::endl;
}

void Thing::reaction() {
    std::cout << "THING " << id << ": reaction()" << std::endl;
}

std::string Thing::toString() const {
    // std::to_string turns an int into a std::string so we can join it
    // with "+", similar to Java's string concatenation.
    return "THING " + std::to_string(id) + ": toString()";
}
