#ifndef LINEARNODE_H
#define LINEARNODE_H

/**
 * Represents a node in a linked list.
 *
 * MEMORY NOTE: In Java, nodes were created with "new" and reclaimed by the
 * garbage collector. C++ has no GC, so we mirror Java's pointer model with
 * RAW pointers (new / nullptr). The owning collection is responsible for
 * "delete"-ing every node it created (see LinkedStack / LinkedQueue
 * destructors). A LinearNode itself does NOT delete its "next" -- the
 * collection walks the chain and frees each node.
 *
 * @author Java Foundations
 * @version 4.0
 */
template <typename T>
class LinearNode {
private:
    LinearNode<T>* next;
    T element;

public:
    /** Creates an empty node. */
    LinearNode()
        : next(nullptr), element() {}

    /** Creates a node storing the specified element. */
    LinearNode(T elem)
        : next(nullptr), element(elem) {}

    /** Returns the node that follows this one. */
    LinearNode<T>* getNext() {
        return next;
    }

    /** Sets the node that follows this one. */
    void setNext(LinearNode<T>* node) {
        next = node;
    }

    /** Returns the element stored in this node. */
    T getElement() {
        return element;
    }

    /** Sets the element stored in this node. */
    void setElement(T elem) {
        element = elem;
    }
};

#endif
