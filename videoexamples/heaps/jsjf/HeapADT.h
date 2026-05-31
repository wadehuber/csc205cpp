#ifndef HEAPADT_H
#define HEAPADT_H

#include "BinaryTreeADT.h"

// HeapADT defines the interface to a Heap.
//
// In Java this was "interface HeapADT<T> extends BinaryTreeADT<T>". In C++
// interface inheritance becomes public inheritance of the base interface
// template.
template <typename T>
class HeapADT : public virtual BinaryTreeADT<T> {   // virtual: shared base in the diamond
public:
    virtual ~HeapADT() = default;

    // Adds the specified object to this heap.
    virtual void addElement(T obj) = 0;

    // Removes the element with the lowest value from this heap.
    virtual T removeMin() = 0;

    // Returns a reference to the element with the lowest value in this heap.
    virtual T findMin() = 0;
};

#endif
