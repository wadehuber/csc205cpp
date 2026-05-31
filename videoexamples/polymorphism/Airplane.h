#ifndef AIRPLANE_H
#define AIRPLANE_H

#include "animals/Flyer.h"

// An Airplane is not an Animal, but it IS a Flyer.
// Java: "class Airplane implements Flyer".
class Airplane : public Flyer {
public:
    Airplane();

    void fly() override;
};

#endif
