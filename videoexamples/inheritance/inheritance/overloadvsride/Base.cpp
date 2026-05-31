#include "Base.h"
#include <iostream>

Base::Base(int a) {
    this->a = a;
}

void Base::change(int x) {
    std::cout << "BASE: change with int parameter" << std::endl;
    a = x;
}

void Base::print() {
    std::cout << "BASE: a=" << a << std::endl;
}
