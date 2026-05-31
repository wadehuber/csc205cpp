#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

// Abstract base class (Java: "public abstract class Animal").
class Animal {
protected:
    // "protected" so subclasses may use name directly, like the Java field.
    std::string name;

public:
    Animal(std::string name);

    // Polymorphic base classes need a virtual destructor in C++.
    virtual ~Animal() = default;

    // Pure virtual ("= 0"): Java's "public abstract void speak();".
    virtual void speak() = 0;

    // Overridable in subclasses, so it must be virtual.
    virtual void move();

    std::string getName() const;
};

#endif
