#ifndef DOG_H
#define DOG_H

#include <string>
#include "Animal.h"

// "extends Animal" -> ": public Animal".
class Dog : public Animal {
public:
    Dog(std::string name);

    void speak() override;
    void move() override;

    // A Dog can do something Animals can't.
    void fetch();
};

#endif
