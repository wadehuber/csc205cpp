#ifndef MYOTHERCLASS_H
#define MYOTHERCLASS_H

#include <string>
#include "MyInterface.h"

class MyOtherClass : public MyInterface {
public:
    MyOtherClass();

    void hello();

    int add(int num) override;
    void greet(std::string name) override;
};

#endif
