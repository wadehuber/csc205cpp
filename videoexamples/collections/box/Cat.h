// Cat.h
// C++ version of Cat.java (header).
// A cat to put in a Box.

#ifndef CAT_H
#define CAT_H

#include <string>
#include <ostream>

class Cat {
private:
    std::string name;

public:
    // Java's Box<Cat>() left the box "empty" (null). C++ needs a real object
    // to default-construct, so we give Cat a no-arg constructor (empty name).
    // box3 always has a real Cat add()-ed before it is printed.
    Cat();
    Cat(std::string name);

    void speak();

    // Java's toString().
    std::string toString() const;
};

// So that a Cat can be printed directly with std::cout << cat (and so a
// Box<Cat> can print the Cat inside it). Java got this for free from
// toString(); in C++ we wire it up with operator<<.
std::ostream& operator<<(std::ostream& os, const Cat& cat);

#endif
