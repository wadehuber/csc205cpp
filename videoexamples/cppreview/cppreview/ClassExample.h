// ClassExample.h
// C++ version of ClassExample.java (declaration / header part).
//
// Java review topic: writing a class.
// In Java a class lives in one .java file. In C++ we split it into a HEADER
// (.h) that DECLARES the class and its members, and a .cpp that DEFINES the
// method bodies. The header is what other files #include.

#ifndef CLASSEXAMPLE_H   // include guard: prevents this header being read twice
#define CLASSEXAMPLE_H

#include <string>

class ClassExample {
private:
    // Private members are only visible inside the class (same as Java).
    std::string name;
    int count;
    int num;

public:
    // Constructors: like Java, named after the class with no return type.
    // C++ supports overloading (multiple constructors) just like Java.
    ClassExample(std::string name, int num);
    ClassExample(std::string name, int num, int count);

    int getNum() const;        // const = this method does not modify the object
    void setNum(int num);
    void increment();

    // Java's toString() override becomes a normal const method here. We print
    // with: std::cout << obj.toString();
    std::string toString() const;
};

#endif
