#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <string>

/**
 * QueueADT defines the interface to a queue collection.
 *
 * Java's "interface QueueADT<T>" becomes a C++ class template made up of
 * pure virtual functions (= 0). A virtual destructor is added so that
 * deleting through a base pointer is safe.
 *
 * @author Java Foundation
 * @version 4.0
 */
template <typename T>
class QueueADT {
public:
    virtual ~QueueADT() = default;

    /** Adds one element to the rear of this queue. */
    virtual void enqueue(T element) = 0;

    /** Removes and returns the element at the front of this queue. */
    virtual T dequeue() = 0;

    /** Returns without removing the element at the front of this queue. */
    virtual T first() = 0;

    /** Returns true if this queue contains no elements. */
    virtual bool isEmpty() = 0;

    /** Returns the number of elements in this queue. */
    virtual int size() = 0;

    /** Returns a string representation of this queue. */
    virtual std::string toString() = 0;
};

#endif
