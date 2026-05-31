#ifndef BOXER_H
#define BOXER_H

#include <string>
#include "Fights.h"

class Boxer : public Fights {
private:
    std::string name;

public:
    Boxer(std::string name);

    void attack() override;
    void receiveHit(int x) override;

    std::string toString() const;
};

#endif
