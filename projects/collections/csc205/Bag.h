#ifndef BAG_H
#define BAG_H

// Java: "interface Bag<T> extends Iterable<T>".
//
// A generic (templated) interface. "template <typename T>" is C++'s way
// of writing the <T> part: T is a placeholder for whatever type the user
// stores in the bag.
//
// (Java's "extends Iterable<T>" means "you can use a for-each loop on it".
// In C++ that ability comes from providing begin()/end() in the concrete
// class. This is starter code, so we leave that out for now.)
template <typename T>
class Bag {
public:
    virtual ~Bag() = default;

    virtual bool isEmpty() = 0;
    virtual int count() = 0;
    virtual void addToBag(T item) = 0;
};

#endif
