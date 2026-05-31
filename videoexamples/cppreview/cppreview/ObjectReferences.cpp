// ObjectReferences.cpp
// C++ version of ObjectReferences.java
//
// Java review topic: primitive variables vs object reference variables.
//
// THIS IS ONE OF THE BIGGEST JAVA -> C++ DIFFERENCES:
//   - In Java, a variable of an object type (like Thing) is a REFERENCE: it
//     points at an object on the heap. Assigning anthr = tng makes both names
//     point at the SAME object, so changing one changes "both".
//   - In C++, a plain variable is a VALUE. "Thing anthr = tng;" makes a COPY.
//     Changing one would NOT affect the other.
//
// To get Java's "share the same object" behavior in C++ you use a reference
// (Thing&) or a pointer (Thing*). Below we use a POINTER so that reassigning
// (anthr = &tng) works just like Java's reference reassignment, and the output
// matches the Java program.

#include <iostream>
#include <string>

// A small helper class (Java had this as a private static nested class).
class Thing {
private:
    int num;
    std::string name;

public:
    Thing(int num, std::string name) : num(num), name(name) {}

    void setNum(int n) { this->num = n; }

    void print() {
        std::cout << "Thing [num=" << num << ", name=" << name << "]" << std::endl;
    }
};

int main() {
    // Primitive variables (same idea as Java)
    int x = 10;
    double pi = 3.14159;

    // "Object reference variables."
    // The actual Thing objects are tng, anthr, yeti (real values on the stack).
    // To mimic Java references we use POINTERS that point at them.
    std::string str = "Hello, CSC205";
    Thing tng(42, "Gorgu");
    Thing anthr(4, "Privet");
    Thing yeti(2020, "Arizona");

    Thing* pTng   = &tng;     // like Java's reference variable "tng"
    Thing* pAnthr = &anthr;   // like Java's "anthr"
    Thing* pYeti  = &yeti;    // like Java's "yeti"

    // Print everything out.
    std::cout << "Primitive variables:" << std::endl;
    std::cout << "   x = " << x << std::endl;
    std::cout << "  pi = " << pi << std::endl;
    std::cout << std::endl;
    // Java printed the object reference (which calls toString or prints a hash).
    // Our Thing has no toString, so we print the pointer addresses to make the
    // point that these are references/addresses, not values. (These addresses
    // will differ from Java's output and from run to run.)
    std::cout << "Object reference variables:" << std::endl;
    std::cout << "   str = " << str << std::endl;
    std::cout << "   tng = " << pTng << std::endl;
    std::cout << " anthr = " << pAnthr << std::endl;
    std::cout << "  yeti = " << pYeti << std::endl;

    std::cout << std::endl;
    pTng->print();
    pAnthr->print();
    pYeti->print();

    // Java: anthr = tng;  -> both references now point at the same object.
    // C++ : copy the POINTER so both point at the same Thing (Java behavior).
    pAnthr = pTng;
    std::cout << std::endl;
    std::cout << "After anthr = tng" << std::endl;
    pTng->print();
    pAnthr->print();

    // Because pAnthr and pTng point at the SAME object, this change shows up
    // through both -- exactly like Java references.
    pAnthr->setNum(123);
    std::cout << std::endl;
    std::cout << "After anthr.setNum(123)" << std::endl;
    pTng->print();
    pAnthr->print();

    std::cout << std::endl;
    std::cout << "Object reference variables:" << std::endl;
    std::cout << "   str = " << str << std::endl;
    std::cout << "   tng = " << pTng << std::endl;
    std::cout << " anthr = " << pAnthr << std::endl;   // now equal to pTng's address
    std::cout << "  yeti = " << pYeti << std::endl;

    return 0;
}
