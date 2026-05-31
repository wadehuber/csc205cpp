// BoxDriver.cpp
// C++ version of BoxDriver.java.
//
// Shows the generic Box<T> holding different types.
//
// A NOTE ABOUT box4:
// In Java, box4 held an ArrayList<Object>. Java's "Object" lets one list mix
// completely different types (an Integer, a String, a char, a Cat, even
// another Box). C++ containers are homogeneous -- every element must be the
// SAME type -- so there is no simple, idiomatic equivalent of a mixed list.
// To keep it simple we store each item's TEXT form in a std::vector<string>.
//
// Java also stored a REFERENCE to box1 inside that list, so when box1 later
// changed to "Goodbye!", the printout of box4 changed too. C++ stored a text
// snapshot instead, so below we update that snapshot by hand after box1
// changes -- producing the same output the Java program produced.

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Box.h"
#include "Cat.h"

// Helper: turn a std::vector<std::string> into Java's list style: [a, b, c]
static std::string listToString(const std::vector<std::string>& list) {
    std::ostringstream out;
    out << "[";
    for (std::size_t i = 0; i < list.size(); i++) {
        out << list[i];
        if (i + 1 < list.size()) {
            out << ", ";
        }
    }
    out << "]";
    return out.str();
}

int main() {
    Box<std::string> box1("Hello, world!");
    Box<int> box2(6);
    Box<Cat> box3;
    Box<std::vector<std::string>> box4;

    // Add things to a list. In Java these were different Object types;
    // here we store each one's text form.
    std::vector<std::string> stuff;
    stuff.push_back("1");
    stuff.push_back("Burrow");
    stuff.push_back("A");
    stuff.push_back(Cat("Fluffy").toString());
    stuff.push_back(box1.toString());          // snapshot of box1 right now

    box3.add(Cat("Schrodinger"));
    box4.add(stuff);

    // In Java this fetched the same list object and added to it. We fetch a
    // copy, add to it, and put it back so box4 sees the new items.
    std::vector<std::string> tempList = box4.whatsInTheBox();
    tempList.push_back("7");
    tempList.push_back("CSC205");
    box4.add(tempList);

    std::cout << "Box 1: " << box1.toString() << std::endl;
    std::cout << "Box 2: " << box2.toString() << std::endl;
    std::cout << "Box 3: " << box3.toString() << std::endl;
    std::cout << "Box 4: " << "Box [item=" << listToString(box4.whatsInTheBox()) << "]" << std::endl;

    // box1.add(4);    // would not compile: box1 only holds std::string
    // box2.add("Test"); // would not compile: box2 only holds int
    box1.add("Goodbye!");
    box2.add(10);
    box3.add(Cat("Mittens"));

    // Java's box4 still pointed at box1, so it now shows "Goodbye!".
    // We update the snapshot by hand to get the same result.
    tempList[4] = box1.toString();
    box4.add(tempList);

    std::cout << std::endl;
    std::cout << "Box 1: " << box1.toString() << std::endl;
    std::cout << "Box 2: " << box2.toString() << std::endl;
    std::cout << "Box 3: " << box3.toString() << std::endl;
    std::cout << "Box 4: " << "Box [item=" << listToString(box4.whatsInTheBox()) << "]" << std::endl;

    return 0;
}
