#ifndef MYCLASS_H
#define MYCLASS_H

#include <string>
#include "MyInterface.h"

// Java's "class MyClass implements MyInterface" becomes
// "class MyClass : public MyInterface".
class MyClass : public MyInterface {
public:
    MyClass();

    int add(int num) override;
    void greet(std::string name) override;
};

#endif
