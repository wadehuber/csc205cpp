#ifndef FLYER_H
#define FLYER_H

// Java's "public interface Flyer" becomes a C++ class containing ONLY
// pure virtual functions ("= 0"). Any class that inherits from it must
// provide its own fly().
class Flyer {
public:
    virtual ~Flyer() = default;

    virtual void fly() = 0;
};

#endif
