#ifndef ARRAYHEAP_H
#define ARRAYHEAP_H

#include "ArrayBinaryTree.h"
#include "HeapADT.h"
#include "exceptions/EmptyCollectionException.h"

// ArrayHeap provides an array implementation of a minheap.
//
// HEADER-ONLY TEMPLATE (mirrors the Java generic class).
//
// Java was "extends ArrayBinaryTree<T> implements HeapADT<T>". Comparable's
// compareTo(b) < 0 becomes operator< (a < b); the element type must define
// operator< (int and our demo classes do).
//
// The protected members count, tree, modCount and the helpers isNull()/put()
// come from ArrayBinaryTree<T>; in C++ templates they must be reached through
// this-> because the base is a dependent type.
template <typename T>
class ArrayHeap : public ArrayBinaryTree<T>, public HeapADT<T> {
private:
    // Reorders this heap to maintain the ordering property after adding.
    void heapifyAdd() {
        T temp;
        int next = this->count - 1;

        temp = this->tree[next];

        while ((next != 0) &&
               (temp < this->tree[(next - 1) / 2]))   // Java: temp.compareTo(...) < 0
        {
            this->put(next, this->tree[(next - 1) / 2]);
            next = (next - 1) / 2;
        }

        this->put(next, temp);
    }

    // Reorders this heap after the minimum element has been removed.
    void heapifyRemove() {
        T temp;
        int node = 0;
        int left = 1;
        int right = 2;
        int next;

        if (this->isNull(left) && this->isNull(right))
            next = this->count;
        else if (this->isNull(right))
            next = left;
        else if (this->tree[left] < this->tree[right])
            next = left;
        else
            next = right;
        temp = this->tree[node];

        while ((next < this->count) &&
               (this->tree[next] < temp))   // Java: tree[next].compareTo(temp) < 0
        {
            this->put(node, this->tree[next]);
            node = next;
            left = 2 * node + 1;
            right = 2 * (node + 1);
            if (this->isNull(left) && this->isNull(right))
                next = this->count;
            else if (this->isNull(right))
                next = left;
            else if (this->tree[left] < this->tree[right])
                next = left;
            else
                next = right;
        }
        this->put(node, temp);
    }

public:
    // Creates an empty heap.
    ArrayHeap() : ArrayBinaryTree<T>() {}

    // Adds the specified element to this heap in the appropriate position.
    void addElement(T obj) override {
        if (this->count == (int) this->tree.size())
            this->expandCapacity();

        this->put(this->count, obj);
        this->count++;
        this->modCount++;

        if (this->count > 1)
            heapifyAdd();
    }

    // Removes and returns the element with the lowest value in this heap.
    T removeMin() override {
        if (this->isEmpty())
            throw EmptyCollectionException("ArrayHeap");

        T minElement = this->tree[0];
        this->put(0, this->tree[this->count - 1]);
        heapifyRemove();
        this->count--;
        this->modCount++;

        return minElement;
    }

    // Returns the element with the lowest value in this heap.
    T findMin() override {
        if (this->isEmpty())
            throw EmptyCollectionException("ArrayHeap");

        return this->tree[0];
    }

    // ----------------------------------------------------------------------
    // Disambiguation: isEmpty(), size(), contains(), find(), getRootElement(),
    // and toString() are declared pure in BOTH base interfaces (via
    // ArrayBinaryTree's BinaryTreeADT and HeapADT's BinaryTreeADT). The
    // implementations live in ArrayBinaryTree<T>; we forward to them so the
    // class is concrete and unambiguous.
    // ----------------------------------------------------------------------
    bool isEmpty() override { return ArrayBinaryTree<T>::isEmpty(); }
    int size() override { return ArrayBinaryTree<T>::size(); }
    bool contains(T t) override { return ArrayBinaryTree<T>::contains(t); }
    T find(T t) override { return ArrayBinaryTree<T>::find(t); }
    T getRootElement() override { return ArrayBinaryTree<T>::getRootElement(); }
    std::string toString() override { return ArrayBinaryTree<T>::toString(); }
};

#endif
