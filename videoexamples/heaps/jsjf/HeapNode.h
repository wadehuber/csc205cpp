#ifndef HEAPNODE_H
#define HEAPNODE_H

#include "BinaryTreeNode.h"

// HeapNode represents a binary tree node with a parent pointer for use in
// heaps.
//
// HEADER-ONLY TEMPLATE (mirrors the Java generic class).
//
// Java was "extends BinaryTreeNode<T>". The parent pointer is a NON-OWNING
// back-reference: we never delete it here (the base BinaryTreeNode destructor
// recursively deletes children, which is what actually frees the tree).
template <typename T>
class HeapNode : public BinaryTreeNode<T> {
public:
    HeapNode<T>* parent;

    // Creates a new heap node with the specified data.
    HeapNode(T obj) : BinaryTreeNode<T>(obj) {
        parent = nullptr;
    }

    // Return the parent of this node.
    HeapNode<T>* getParent() { return parent; }

    // Sets the element stored at this node.
    void setElement(T obj) { this->element = obj; }

    // Sets the parent of this node.
    void setParent(HeapNode<T>* node) { parent = node; }
};

#endif
