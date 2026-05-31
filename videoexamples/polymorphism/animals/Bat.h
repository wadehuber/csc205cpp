#ifndef BAT_H
#define BAT_H

#include <string>
#include "Animal.h"
#include "Flyer.h"

// Java: "class Bat extends Animal implements Flyer".
// C++ uses multiple inheritance: extend Animal AND the Flyer interface.
class Bat : public Animal, public Flyer {
public:
    Bat(std::string name);

    void speak() override;
    void move() override;
    void fly() override;   // from Flyer
};

#endif
