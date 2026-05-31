#include <iostream>
#include <vector>

#include "animals/Animal.h"
#include "animals/Dog.h"
#include "animals/Bear.h"
#include "fighters/Fights.h"
#include "fighters/Boxer.h"

int main() {
    /* Cannot instantiate an abstract class:
       Animal a("NoName");   // compiler error
       a.speak();
    */

    // Objects live on the stack. We never call new/delete; when main()
    // ends, these are cleaned up automatically.
    Dog d("Fido");
    Bear b("Wallace");
    Boxer x("Muhammed Ali");

    std::cout << "Use a Dog reference to a Dog object" << std::endl;
    d.speak();
    d.move();
    d.fetch();
    std::cout << std::endl;

    // An Animal* (pointer) can point at any kind of Animal. This is how
    // C++ does what Java's "Animal a = d;" does. We use "a->" instead of
    // "a." because a is a pointer.
    Animal* a = &d;
    std::cout << "Use a Animal reference to a Dog object" << std::endl;
    a->speak();
    a->move();
    // a->fetch();   // an Animal pointer doesn't know how to fetch
    std::cout << std::endl;

    std::cout << "Use a Bear reference to a Bear object" << std::endl;
    b.speak();
    b.move();
    std::cout << std::endl;

    a = &b;   // the same pointer can now point at a Bear
    std::cout << "Use a Animal reference to a Bear object" << std::endl;
    a->speak();
    a->move();
    std::cout << std::endl;

    // To build an "array of Animals" that holds different kinds of Animal,
    // we use a vector of Animal pointers. We need named objects to point
    // at (instead of Java's inline "new Dog(...)").
    Dog rover("Rover");
    Bear smokey("Smokey");
    Dog doug("Doug");

    std::cout << "\nAnimal array of Dog & Bear references" << std::endl;
    std::vector<Animal*> arr = { &d, &b, &rover, &smokey, &doug };
    // A normal counting loop, like the Java version.
    for (std::size_t ii = 0; ii < arr.size(); ii++) {
        std::cout << " " << ii << "  : " << arr[ii]->toString() << "\t";
        arr[ii]->speak();
    }

    std::cout << "\nUse a Boxer reference to a Boxer object" << std::endl;
    x.attack();
    x.receiveHit(1);
    x.receiveHit(22);
    std::cout << std::endl;

    // Polymorphism through an interface:
    // Fights f = new Fights();   // can't instantiate an interface
    Fights* f = &x;
    std::cout << "Use a Fights reference to a Boxer object" << std::endl;
    f->attack();
    f->receiveHit(1);
    f->receiveHit(22);
    std::cout << std::endl;

    f = &b;   // a Bear is also a Fights
    std::cout << "Use a Fights reference to a Bear object" << std::endl;
    f->attack();
    f->receiveHit(1);
    f->receiveHit(22);
    std::cout << std::endl;

    std::cout << "Fights array of Boxer & Bear references" << std::endl;
    Boxer floyd("Floyd Patterson");
    Bear yogi("Yogi");
    Boxer drago("Ivan Drago");
    std::vector<Fights*> fighters = { &x, &b, &floyd, &yogi, &drago };
    // A range-based for loop, like Java's for-each: "for (Fights z : fighters)".
    // NOTE: unlike Java, C++ does not give every object a toString(), and our
    // Fights interface doesn't declare one, so we just call attack() here.
    for (Fights* z : fighters) {
        z->attack();
    }

    return 0;
}
