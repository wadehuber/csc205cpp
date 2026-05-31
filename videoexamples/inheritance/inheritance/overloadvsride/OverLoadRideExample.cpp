#include <iostream>
#include <string>

#include "Derived.h"

int main() {
    Derived example(4, "Java");

    std::cout << "Initial print()" << std::endl;
    example.print();

    std::cout << std::endl;
    std::cout << "Calling change(int)" << std::endl;
    // Resolves to the INHERITED Base::change(int) (kept visible by
    // 'using Base::change;' in Derived).
    example.change(11);
    example.print();

    std::cout << std::endl;
    std::cout << "Calling change(String)" << std::endl;
    // std::string overload. A bare "Chandler" is a const char*, so we make
    // it a std::string to pick the change(std::string) overload.
    example.change(std::string("Chandler"));
    example.print();

    std::cout << std::endl;
    std::cout << "Calling change(int, String)" << std::endl;
    example.change(48, "Chandler");
    example.print();

    return 0;
}
