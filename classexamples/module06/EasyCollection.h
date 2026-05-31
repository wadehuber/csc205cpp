#ifndef EASYCOLLECTION_H
#define EASYCOLLECTION_H

// Java: "interface EasyCollection<T> extends Iterable<T>".
//
// A generic (templated) interface. "template <typename T>" is C++'s way
// of writing the <T> part: T is a placeholder for whatever type the user
// stores in the collection.
//
// (Java's "extends Iterable<T>" means "you can use a for-each loop on it".
// In C++ that ability comes from providing begin()/end(), which the
// implementing class MyCollection does directly.)
template <typename T>
class EasyCollection {
public:
    virtual ~EasyCollection() = default;

    virtual void add(T thing) = 0;
    virtual void remove(T thing) = 0;
};

#endif
