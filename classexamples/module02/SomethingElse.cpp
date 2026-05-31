#include "SomethingElse.h"
#include <iostream>

SomethingElse::SomethingElse(int id) : Thing(id) {
    std::cout << "SOMETHINGELSE " << id << ": Constructor" << std::endl;
}

void SomethingElse::action() {
    std::cout << "SOMETHINGELSE " << id << ": action()" << std::endl;
}

void SomethingElse::reaction() {
    std::cout << "SOMETHINGELSE " << id << ": reaction()" << std::endl;
}

void SomethingElse::megaReaction() {
    std::cout << "SOMETHINGELSE: megaReaction -- BEGIN" << std::endl;

    std::cout << "\tthis: ";
    this->reaction();           // calls SomethingElse::reaction()

    std::cout << "\tsuper: ";
    // "Thing::reaction()" forces the base-class version, like Java's
    // super.reaction().
    Thing::reaction();
    std::cout << "SOMETHINGELSE: megaReaction -- END" << std::endl;
}
