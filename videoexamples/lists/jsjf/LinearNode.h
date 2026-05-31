#ifndef LINEARNODE_H
#define LINEARNODE_H

/**
 * LinearNode represents a node in a linked list.
 *
 * MEMORY NOTE: In Java, nodes were created with "new" and reclaimed by the
 * garbage collector. C++ has no GC, so we mirror Java's pointer model with
 * RAW pointers (new / nullptr). The owning list is responsible for "delete"-ing
 * every node it created (see LinkedList's destructor). A LinearNode itself does
 * NOT delete its "next" -- the list walks the chain and frees each node.
 *
 * @author Java Foundations
 * @version 4.0
 */
template <typename E>
class LinearNode {
private:
    LinearNode<E>* next;
    E element;

public:
    /** Creates an empty node. */
    LinearNode()
        : next(nullptr), element() {}

    /** Creates a node storing the specified element. */
    LinearNode(E elem)
        : next(nullptr), element(elem) {}

    /** Returns the node that follows this one. */
    LinearNode<E>* getNext() {
        return next;
    }

    /** Sets the node that follows this one. */
    void setNext(LinearNode<E>* node) {
        next = node;
    }

    /** Returns the element stored in this node. */
    E getElement() {
        return element;
    }

    /** Sets the element stored in this node. */
    void setElement(E elem) {
        element = elem;
    }
};

#endif
