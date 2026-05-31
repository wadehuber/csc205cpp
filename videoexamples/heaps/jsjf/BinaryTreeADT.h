#ifndef BINARYTREEADT_H
#define BINARYTREEADT_H

#include <string>

// BinaryTreeADT defines the interface to a binary tree data structure.
//
// In Java this was an "interface". In C++ an interface is a class template
// with only pure virtual functions (= 0) plus a virtual destructor.
//
// NOTE on iterators: the Java interface also declared iterator(),
// iteratorInOrder(), iteratorPreOrder(), iteratorPostOrder() and
// iteratorLevelOrder(), all returning a java.util.Iterator<T>. C++ has no
// single universal iterator type, and none of the drivers in this package
// call those methods directly (toString() does the in-order walk itself), so
// we omit them here to keep the example simple.
template <typename T>
class BinaryTreeADT {
public:
    virtual ~BinaryTreeADT() = default;

    // Returns a reference to the root element.
    virtual T getRootElement() = 0;

    // Returns true if this binary tree is empty and false otherwise.
    virtual bool isEmpty() = 0;

    // Returns the number of elements in this binary tree.
    virtual int size() = 0;

    // Returns true if the tree contains an element matching targetElement.
    virtual bool contains(T targetElement) = 0;

    // Returns the specified element if it is found in this tree.
    virtual T find(T targetElement) = 0;

    // Returns the string representation of this binary tree.
    virtual std::string toString() = 0;
};

#endif
