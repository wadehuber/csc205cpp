#ifndef BINARYSEARCHTREEADT_H
#define BINARYSEARCHTREEADT_H

#include "BinaryTreeADT.h"

// BinarySearchTreeADT defines the interface to a binary search tree.
//
// In Java this was "interface BinarySearchTreeADT<T> extends BinaryTreeADT<T>".
template <typename T>
class BinarySearchTreeADT : public virtual BinaryTreeADT<T> {   // virtual: shared base in the diamond
public:
    virtual ~BinarySearchTreeADT() = default;

    // Adds the specified element to the proper location in this tree.
    virtual void addElement(T element) = 0;

    // Removes and returns the specified element from this tree.
    virtual T removeElement(T targetElement) = 0;

    // Removes all occurrences of the specified element from this tree.
    virtual void removeAllOccurrences(T targetElement) = 0;

    // Removes and returns the smallest element from this tree.
    virtual T removeMin() = 0;

    // Removes and returns the largest element from this tree.
    virtual T removeMax() = 0;

    // Returns the smallest element in this tree without removing it.
    virtual T findMin() = 0;

    // Returns the largest element in this tree without removing it.
    virtual T findMax() = 0;
};

#endif
