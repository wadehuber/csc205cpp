#include <iostream>

#include "MyClass.h"

// Java prints objects with toString() automatically (e.g. "A:" + A).
// In C++ we call x.toString() explicitly.
void doCompare(const MyClass& m1, const MyClass& m2) {
    if (m1.compareTo(m2) == 0)
        std::cout << m1.toString() << " and " << m2.toString() << " are equal." << std::endl;
    else if (m1.compareTo(m2) < 0)
        std::cout << m1.toString() << " is smaller than " << m2.toString() << std::endl;
    else if (m1.compareTo(m2) > 0)
        std::cout << m1.toString() << " is bigger  than " << m2.toString() << std::endl;
}

int main() {
    MyClass A(2, "Hello");
    MyClass B(1, "World");

    std::cout << "A:" << A.toString() << std::endl;
    std::cout << "B:" << B.toString() << std::endl;

    doCompare(A, A);
    doCompare(B, B);
    doCompare(A, B);
    doCompare(B, A);

    return 0;
}
