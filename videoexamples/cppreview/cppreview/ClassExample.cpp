// ClassExample.cpp
// C++ version of ClassExample.java (definitions + main).
//
// Method bodies are defined here using the ClassExample:: prefix to say which
// class they belong to.

#include "ClassExample.h"
#include <iostream>
#include <string>

// Java had this(name, num, 0) to delegate to the 3-arg constructor.
// C++ supports constructor delegation with the same idea, in the initializer list.
ClassExample::ClassExample(std::string name, int num)
    : ClassExample(name, num, 0) {
}

// The 3-argument constructor does the real work.
// (Java called super() here; in C++ there is no parent so nothing to call.)
ClassExample::ClassExample(std::string name, int num, int count) {
    this->name = name;
    setNum(num);
    this->count = count;
}

int ClassExample::getNum() const {
    return num;
}

void ClassExample::setNum(int num) {
    if (num < 0) {
        this->num = 0;
    }
    else {
        this->num = num;
    }
}

void ClassExample::increment() {
    this->count++;
}

// Returns a string representation of the object (no printing inside!).
std::string ClassExample::toString() const {
    return ("ClassExample [name=" + name + ", count=" + std::to_string(count) +
            ", num=" + std::to_string(num) + "]");
}

int main() {
    std::cout << "Test of ClassExample class" << std::endl;

    // Instantiate some objects. In C++ we usually create objects as plain
    // values (on the stack) -- no "new" needed for this simple example.
    ClassExample object1("Object1", 10);
    ClassExample object2("Object2", 20, 100);

    // Our toString method lets us print the objects easily.
    std::cout << object1.toString() << std::endl;
    std::cout << object2.toString() << std::endl;
    std::cout << std::endl;

    // Change object1
    object1.setNum(45);
    object1.increment();

    // Change object2
    object2.setNum(-3);
    for (int ii = 0; ii < 23; ii++) {
        object2.increment();
    }

    std::cout << "After changing the objects:" << std::endl;
    std::cout << object1.toString() << std::endl;
    std::cout << object2.toString() << std::endl;

    return 0;
}
