#ifndef BEAR_H
#define BEAR_H

#include <string>
#include "Animal.h"
#include "../fighters/Fights.h"

// Java: "class Bear extends Animal implements Fights".
// In C++, extending a class and implementing an interface both look the
// same: we list both base classes after the colon. A Bear is therefore
// both an Animal AND a Fights.
class Bear : public Animal, public Fights {
public:
    Bear(std::string name);

    void speak() override;       // required by Animal
    void attack() override;      // required by Fights
    void receiveHit(int x) override;  // required by Fights
};

#endif
