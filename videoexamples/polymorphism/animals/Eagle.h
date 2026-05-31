#ifndef EAGLE_H
#define EAGLE_H

#include <string>
#include "Animal.h"
#include "Flyer.h"

// Java: "class Eagle extends Animal implements Flyer".
class Eagle : public Animal, public Flyer {
public:
    Eagle(std::string name);

    void speak() override;
    void move() override;
    void fly() override;   // from Flyer
};

#endif
