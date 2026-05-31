#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

// Abstract base class (Java: "public abstract class Animal").
class Animal {
private:
    std::string name;

public:
    Animal(std::string name);
    virtual ~Animal() = default;

    // Pure virtual: every kind of Animal must say how it speaks.
    virtual void speak() = 0;

    virtual void move();

    std::string getName() const;

protected:
    // "protected" so subclasses (but not outside code) may change the name.
    void setName(std::string n);

public:
    virtual std::string toString() const;
};

#endif
