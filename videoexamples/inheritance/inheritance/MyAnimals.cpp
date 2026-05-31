#include <iostream>

#include "animals/Animal.h"
#include "animals/Cat.h"
#include "animals/Dog.h"
#include "animals/SugarGlider.h"

int main() {
    // Animal a("George");   // Can't instantiate an abstract Animal

    // Objects live on the stack. We never call new/delete; when main()
    // ends, these are cleaned up automatically.
    Dog d("Buck");
    Cat c("Eek");

    // Java: "Animal a = new Dog("Copper");". In C++ an Animal* (pointer)
    // plays the role of a base-class reference to a Dog object. We make a
    // named Dog and point an Animal* at it.
    Dog copper("Copper");
    Animal* a = &copper;

    std::cout << "Dog d: " << std::endl;
    d.speak();
    d.move();
    d.fetch();
    std::cout << std::endl;

    std::cout << "Cat c: " << std::endl;
    c.speak();
    c.move();
    std::cout << std::endl;

    std::cout << "Animal a: " << std::endl;
    // a->speak()/a->move() dispatch to Dog's versions (virtual = polymorphism).
    a->speak();
    a->move();
    // a->fetch();   // an Animal pointer doesn't know how to fetch
    std::cout << std::endl;

    SugarGlider sg("Mike");
    sg.speak();
    sg.move();

    return 0;
}
