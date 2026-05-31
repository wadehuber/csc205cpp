// StaticExample.cpp
// C++ version of StaticExample.java -- the driver for the Static class.

#include "Static.h"
#include <iostream>

int main() {
    Static static1("Kendra", 13);
    Static static2("Seth", 11);

    std::cout << static1.toString() << std::endl;
    std::cout << static2.toString() << std::endl;

    std::cout << std::endl;
    static1.nonStaticMethod(1);
    std::cout << static1.toString() << std::endl;
    std::cout << static2.toString() << std::endl;

    std::cout << std::endl;
    static2.nonStaticMethod(2);
    std::cout << static1.toString() << std::endl;
    std::cout << static2.toString() << std::endl;

    std::cout << std::endl;
    // Called on the class itself (Static::), not an object -- like Java's Static.staticMethod(10).
    Static::staticMethod(10);
    std::cout << static1.toString() << std::endl;
    std::cout << static2.toString() << std::endl;

    return 0;
}
