#ifndef BINARYSEARCHTREELIST_H
#define BINARYSEARCHTREELIST_H

#include <string>
#include "LinkedBinarySearchTree.h"
#include "ListADT.h"
#include "OrderedListADT.h"
#include "ArrayUnorderedList.h"

// BinarySearchTreeList represents an ordered list implemented using a binary
// search tree.
//
// HEADER-ONLY TEMPLATE (mirrors the Java generic class).
//
// Java was "implements ListADT<T>, OrderedListADT<T>, Iterable<T>". Since
// OrderedListADT<T> already extends ListADT<T> (virtually), we inherit just
// OrderedListADT<T> here; that supplies the full ListADT interface too.
//
// NOTE: several methods delegate to LinkedBinarySearchTree methods that are
// still PROGRAMMING-PROJECT STUBS (removeMin/removeMax/findMin/findMax/find),
// so they behave exactly like the unfinished Java starter code.
template <typename T>
class BinarySearchTreeList : public OrderedListADT<T> {
protected:
    LinkedBinarySearchTree<T> tree;

public:
    // Creates an empty BinarySearchTreeList.
    BinarySearchTreeList() {
        // tree is default-constructed (empty)
    }

    virtual ~BinarySearchTreeList() = default;

    // Adds the given element to this list.
    void add(T element) override {
        tree.addElement(element);
    }

    // Removes and returns the first element from this list.
    T removeFirst() override {
        return tree.removeMin();
    }

    // Removes and returns the last element from this list.
    T removeLast() override {
        return tree.removeMax();
    }

    // Removes and returns the specified element from this list.
    T remove(T element) override {
        return tree.removeElement(element);
    }

    // Returns a reference to the first element on this list.
    T first() override {
        return tree.findMin();
    }

    // Returns a reference to the last element on this list.
    T last() override {
        return tree.findMax();
    }

    // Returns true if this list contains a matching element.
    bool contains(T target) override {
        return tree.contains(target);
    }

    // Returns true if this list contains no elements.
    bool isEmpty() override {
        return tree.isEmpty();
    }

    // Returns the number of elements in this list.
    int size() override {
        return tree.size();
    }

    // Returns a string representation of this list.
    std::string toString() override {
        return tree.toString();
    }

    // Java exposed an Iterator via iterator() returning tree.iteratorInOrder().
    // In C++ we return the in-order ArrayUnorderedList<T>, which supports
    // range-based for (begin()/end()).
    ArrayUnorderedList<T> iterator() {
        return tree.iteratorInOrder();
    }
};

#endif
