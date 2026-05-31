#include "Derived.h"
#include <iostream>

// super(a) becomes the base initializer list ": Base(a)".
Derived::Derived(int a) : Base(a) {
}

Derived::Derived(int a, std::string s) : Base(a) {
    this->s = s;
}

void Derived::change(std::string y) {
    std::cout << "DERIVED: change with String parameter" << std::endl;
    s = y;
}

void Derived::change(int x, std::string y) {
    std::cout << "DERIVED: change with int & String parameters" << std::endl;
    a = x;
    s = y;
}

void Derived::print() {
    std::cout << "DERIVED: a=" << a << " and s=" << s << std::endl;
}
