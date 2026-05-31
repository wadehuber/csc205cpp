// GenericsExample.cpp
// C++ version of GenericsExample.java.
//
// Shows a generic class (Thing<T>) and a generic function (areSame).
//
// Java's generic method  <T> void areSame(T a, T b)
// becomes a C++ function template:  template <typename T> void areSame(...)

#include <iostream>
#include <string>
#include "Thing.h"

// Generic function. C++ figures out T from the arguments you pass, just like
// Java did. We compare with == ; for our built-in types and std::string this
// behaves like Java's .equals().
template <typename T>
void areSame(T a, T b) {
    if (a == b) {
        std::cout << a << " and " << b << " are the same" << std::endl;
    } else {
        std::cout << a << " and " << b << " are NOT the same" << std::endl;
    }
}

int main() {
    // Create Thing objects with a type (replaces T in the class).
    Thing<int> thing1(1, 5);
    Thing<std::string> thing2("Hello", 10);

    std::cout << "Thing1: " << thing1.toString() << std::endl;
    std::cout << "Thing2: " << thing2.toString() << std::endl;

    std::cout << std::endl;
    std::cout << "areSame testing:" << std::endl;
    areSame(1, 2);
    areSame(5, 5);
    // Use std::string (not "Hello") so T is std::string and == compares text.
    areSame(std::string("Hello"), std::string("World!"));
    areSame(std::string("CGCC"), std::string("CGCC"));

    return 0;
}
