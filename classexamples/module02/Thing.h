#ifndef THING_H
#define THING_H

#include <string>

// Abstract base class.
// In Java this was "public abstract class Thing".
// A class is "abstract" in C++ when it has at least one
// pure virtual function (see action() below).
class Thing {
protected:
    // "protected" so that subclasses can use id directly.
    int id;

public:
    Thing(int id);

    // A base class used through pointers/references should have a
    // virtual destructor. (Java has no destructors; you can think of
    // this as "the right way to clean up a base class object".)
    virtual ~Thing() = default;

    // Pure virtual function ("= 0") -- like Java's "abstract void action()".
    // Subclasses MUST provide their own version.
    virtual void action() = 0;

    // "virtual" means a subclass may override it (all Java methods are
    // virtual by default).
    virtual void reaction();

    // Like Java's toString(). We call it explicitly: cout << x.toString().
    virtual std::string toString() const;
};

#endif
