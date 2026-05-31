// Box.h
// C++ version of Box.java.
//
// A generic "box" that holds one thing of type T.
//
// NOTE: template (generic) classes are written entirely in the header file --
// there is no Box.cpp. C++ must see the whole template to build it for a
// specific type like Box<int> or Box<std::string>.
//
// Java's  class Box<T>   ->   C++  template <typename T> class Box

#ifndef BOX_H
#define BOX_H

#include <string>
#include <sstream>   // std::ostringstream, used to build toString() text

template <typename T>
class Box {
private:
    T item;

public:
    // Java had a no-arg constructor that passed null. In C++ we just
    // default-construct the item (e.g. 0 for int, "" for std::string).
    Box() : item() {}

    Box(T item) : item(item) {}

    void add(T t) {
        item = t;
    }

    T whatsInTheBox() {
        return item;
    }

    // Java's toString(). We use a std::ostringstream so that whatever type T
    // is, it gets turned into text the same way std::cout would print it.
    // (This requires that T itself can be printed with <<; for our own
    // classes like Cat we give them a toString() and print that instead.)
    std::string toString() const {
        std::ostringstream out;
        out << "Box [item=" << item << "]";
        return out.str();
    }
};

#endif
