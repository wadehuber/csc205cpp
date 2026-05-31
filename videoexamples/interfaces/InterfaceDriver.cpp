#include <iostream>

#include "MyClass.h"
#include "MyOtherClass.h"

int main() {
    // Objects live on the stack; no new/delete needed.
    MyClass thing;

    MyOtherClass somethingElse;

    std::cout << "MyClass thing:" << std::endl;
    std::cout << "thing.add(5) = " << thing.add(5) << std::endl;
    thing.greet("CSC205");

    std::cout << std::endl;
    std::cout << "MyOtherClass somethingElse:" << std::endl;
    somethingElse.hello();
    std::cout << "somethingElse.add(5) = " << somethingElse.add(5) << std::endl;
    somethingElse.greet("CSC205");

    return 0;
}
