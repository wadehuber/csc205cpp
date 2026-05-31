#ifndef CAT_H
#define CAT_H

#include <string>
#include "Animal.h"

class Cat : public Animal {
public:
    Cat(std::string name);

    void speak() override;
};

#endif
