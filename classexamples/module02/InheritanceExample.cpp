#include <iostream>
#include "Something.h"
#include "SomethingElse.h"

// This file holds main(), like Java's InheritanceExample with its main().
int main() {

    std::cout << "MAIN: Instantiate Something:" << std::endl;
    // Can't instantiate an object of an abstract class:
    // Thing t(1);   // <-- this would be a compiler error

    Something s(2);
    std::cout << "MAIN: " << s.toString() << std::endl;
    s.action();
    s.reaction();
    std::cout << std::endl;

    SomethingElse e(2);
    std::cout << "MAIN: " << e.toString() << std::endl;
    e.action();
    e.reaction();
    e.megaReaction();
    std::cout << std::endl;

    return 0;
}
