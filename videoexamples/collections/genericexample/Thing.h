// Thing.h
// C++ version of Thing.java.
//
// A generic class - T is a type filled in when you create a Thing.
//
// NOTE: template (generic) classes live entirely in the header file -- there
// is no Thing.cpp. C++ must see the whole template to build it for a specific
// type like Thing<int> or Thing<std::string>.
//
// Java's  class Thing<T>  ->  C++  template <typename T> class Thing

#ifndef THING_H
#define THING_H

#include <string>
#include <sstream>

template <typename T>
class Thing {
private:
    T thing;
    int count;

public:
    Thing(T thing, int count) : thing(thing), count(count) {}

    // Java's toString(). std::ostringstream turns the stored value into text
    // the same way std::cout would print it (works for int, std::string, ...).
    std::string toString() const {
        std::ostringstream out;
        out << "Thing [thing=" << thing << ", count=" << count << "]";
        return out.str();
    }
};

#endif
