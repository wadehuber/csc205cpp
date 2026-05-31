#ifndef SOMETHING_H
#define SOMETHING_H

#include <string>
#include "Thing.h"

// "class Something : public Thing" is C++ for Java's
// "class Something extends Thing".
class Something : public Thing {
public:
    Something(int id);

    // "override" is like Java's @Override -- it tells the compiler we
    // intend to replace a virtual function from the base class.
    void action() override;
    std::string toString() const override;
};

#endif
