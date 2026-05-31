#ifndef SOMETHINGELSE_H
#define SOMETHINGELSE_H

#include "Thing.h"

class SomethingElse : public Thing {
public:
    SomethingElse(int id);

    void action() override;
    void reaction() override;   // this class provides its own reaction()

    // A brand new method, not in the base class.
    void megaReaction();
};

#endif
