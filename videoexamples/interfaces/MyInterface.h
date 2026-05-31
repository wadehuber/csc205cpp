#ifndef MYINTERFACE_H
#define MYINTERFACE_H

#include <string>

// Java's "interface MyInterface" becomes a C++ class that contains ONLY
// pure virtual functions ("= 0"). Any class that inherits from it must
// provide its own versions of these functions.
class MyInterface {
public:
    virtual ~MyInterface() = default;

    // In Java, "final int MYNUM = 42;" is an implicit public/static/final
    // constant on the interface. C++ has no fields in an interface, so we use
    // a "static constexpr" constant (compile-time, shared by all instances).
    static constexpr int MYNUM = 42;

    virtual int add(int num) = 0;
    virtual void greet(std::string name) = 0;
};

#endif
