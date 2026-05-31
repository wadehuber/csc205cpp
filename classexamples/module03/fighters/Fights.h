#ifndef FIGHTS_H
#define FIGHTS_H

// Java's "interface Fights" becomes a C++ class that contains ONLY
// pure virtual functions ("= 0"). Any class that inherits from it must
// provide its own versions of these functions.
class Fights {
public:
    virtual ~Fights() = default;

    virtual void attack() = 0;
    virtual void receiveHit(int x) = 0;
};

#endif
