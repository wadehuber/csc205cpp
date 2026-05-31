#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

// Abstract base class (Java: "public abstract class Animal").
class Animal {
protected:
    // "protected" so subclasses can use 'name' directly, just like in Java.
    std::string name;

public:
    Animal(std::string name);

    // A polymorphic base class always gets a virtual destructor so that
    // deleting/destroying through a base reference cleans up correctly.
    virtual ~Animal() = default;

    // Pure virtual (= 0): this is Java's "public abstract void speak();".
    // It makes Animal abstract, so you cannot create a plain Animal.
    virtual void speak() = 0;

    // 'virtual' because subclasses (Dog) override it; Java methods are
    // virtual by default, so we add 'virtual' here to match that behavior.
    virtual void move();

    std::string getName() const;
};

#endif
