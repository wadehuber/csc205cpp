#include "Something.h"
#include <iostream>

// ": Thing(id)" calls the base-class constructor, like Java's super(id).
Something::Something(int id) : Thing(id) {
    std::cout << "SOMETHING " << id << ": Constructor" << std::endl;
}

void Something::action() {
    std::cout << "SOMETHING " << id << ": action()" << std::endl;
}

std::string Something::toString() const {
    return "Something [id=" + std::to_string(id) + "] toString()";
}
