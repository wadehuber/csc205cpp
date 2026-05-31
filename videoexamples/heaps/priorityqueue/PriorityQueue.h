#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "PrioritizedObject.h"
#include "../jsjf/ArrayHeap.h"

// PriorityQueue implements a priority queue using a heap.
//
// HEADER-ONLY TEMPLATE (mirrors the Java generic class).
//
// The backing minheap stores PrioritizedObject<T> values, ordered by their
// operator< (priority, then arrival order). removeMin() therefore yields the
// next element to serve.
template <typename T>
class PriorityQueue {
private:
    ArrayHeap<PrioritizedObject<T>> pqueue;

public:
    // Creates an empty priority queue.
    PriorityQueue() {}

    // Adds the given element to this PriorityQueue.
    void addElement(T object, int priority) {
        PrioritizedObject<T> obj(object, priority);
        pqueue.addElement(obj);
    }

    // Removes the next highest priority element and returns it.
    T removeNext() {
        PrioritizedObject<T> obj = pqueue.removeMin();
        return obj.getElement();
    }

    int size() {
        return pqueue.size();
    }

    bool isEmpty() {
        return pqueue.isEmpty();
    }
};

#endif
