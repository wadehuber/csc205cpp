#include <iostream>
#include <vector>

#include "animals/Animal.h"
#include "animals/Dog.h"
#include "animals/Cat.h"
#include "animals/Bat.h"
#include "animals/Eagle.h"
#include "animals/Flyer.h"
#include "Airplane.h"

int main() {
    // Animal a("George");   // Can't instantiate an abstract Animal

    // In Java "Animal a = new Dog(...)". In C++ we make a real Dog object
    // and point an Animal* at it; calls through the pointer are polymorphic.
    Dog copper("Copper");
    Animal* a = &copper;

    // Java built an "array of Animal references" with inline "new Dog(...)".
    // In C++ we create named stack objects (no new/delete) and store their
    // addresses in a vector of Animal pointers.
    Dog lassie("Lassie");
    Cat cassie("Cassie");
    Dog togo("Togo");
    Bat bruce("Bruce");
    Eagle eddie("Eddie");
    std::vector<Animal*> arr = { &lassie, &cassie, &togo, &bruce, &eddie };

    // Likewise, an "array of Flyer references": a Bat, Eagles, and an Airplane.
    Bat man("Man");
    Eagle democracy("Democracy");
    Eagle freedom("Freedom");
    Airplane airplane;
    std::vector<Flyer*> f = { &man, &democracy, &freedom, &airplane };

    std::cout << "Animal a: " << std::endl;
    a->speak();
    a->move();
    // a->fetch();   // an Animal pointer doesn't know how to fetch
    std::cout << std::endl;

    // Range-based for loop, like Java's "for (Animal x : arr)".
    std::cout << "Animal array:" << std::endl;
    for (Animal* x : arr) {
        std::cout << "Animal " << x->getName() << std::endl;
        x->speak();
        x->move();
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Flyer array:" << std::endl;
    for (Flyer* x : f) {
        // std::cout << "Flyer " << x->getName() << std::endl;  // Flyer has no name
        x->fly();
    }

    return 0;
}
