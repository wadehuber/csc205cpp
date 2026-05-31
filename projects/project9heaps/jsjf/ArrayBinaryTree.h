#ifndef ARRAYBINARYTREE_H
#define ARRAYBINARYTREE_H

#include <vector>
#include <string>
#include "BinaryTreeADT.h"
#include "ArrayUnorderedList.h"
#include "ElementToString.h"
#include "exceptions/ElementNotFoundException.h"
#include "exceptions/EmptyCollectionException.h"

// ArrayBinaryTree implements the BinaryTreeADT interface using an array.
//
// HEADER-ONLY TEMPLATE (mirrors the Java generic class).
//
// NULL SEMANTICS (important): the Java backing array was an Object[] whose
// unused slots are null, and the algorithms test "tree[i] == null". A C++
// std::vector<T> of value types has no null. We therefore keep a parallel
// std::vector<bool> 'assigned' that marks which slots have ever been written;
// a slot "is null" exactly when it has NOT been assigned. This reproduces the
// Java behavior precisely -- including that removeMin() (in ArrayHeap) does NOT
// clear the slot it copied from, so that slot stays non-null with its old
// (stale) value, just like Java.
template <typename T>
class ArrayBinaryTree : public virtual BinaryTreeADT<T> {   // virtual: shared base in the diamond
private:
    static const int DEFAULT_CAPACITY = 50;

protected:
    int count;
    std::vector<T> tree;
    std::vector<bool> assigned;   // assigned[i] == false mirrors Java tree[i] == null
    int modCount;

    // Helper: is slot i "null" in the Java sense? (never assigned, or beyond
    // the array). Java would throw on a truly out-of-range index, but the
    // drivers never reach that, so treating out-of-range as null is safe.
    bool isNull(int i) const {
        if (i < 0 || i >= (int) tree.size())
            return true;
        return !assigned[i];
    }

    // Helper: write a value into slot i and mark it assigned.
    void put(int i, const T& value) {
        tree[i] = value;
        assigned[i] = true;
    }

public:
    // Creates an empty binary tree.
    ArrayBinaryTree() {
        count = 0;
        tree.resize(DEFAULT_CAPACITY);
        assigned.assign(DEFAULT_CAPACITY, false);
        modCount = 0;
    }

    // Creates a binary tree with the specified element as its root.
    ArrayBinaryTree(T element) {
        count = 1;
        tree.resize(DEFAULT_CAPACITY);
        assigned.assign(DEFAULT_CAPACITY, false);
        modCount = 0;
        put(0, element);
    }

    virtual ~ArrayBinaryTree() = default;

protected:
    // Expand capacity if full (Java: Arrays.copyOf doubling).
    void expandCapacity() {
        tree.resize(tree.size() * 2);
        assigned.resize(assigned.size() * 2, false);   // new slots are "null"
    }

public:
    // Returns the root element of the tree.
    T getRootElement() override {
        if (isEmpty())
            throw EmptyCollectionException("ArrayBinaryTree");

        return tree[0];
    }

    // Returns true if this binary tree is empty and false otherwise.
    bool isEmpty() override {
        return (count == 0);
    }

    // Returns the integer size of this binary tree.
    int size() override {
        return count;
    }

    // Returns true if this tree contains a matching element.
    bool contains(T targetElement) override {
        bool found = false;

        try {
            find(targetElement);
            found = true;
        }
        catch (...) {   // Java caught ElementNotFoundException
            found = false;
        }

        return found;
    }

    // Returns a reference to the specified target element if found, else
    // throws ElementNotFoundException.
    T find(T targetElement) override {
        T temp = T();
        bool found = false;

        for (int i = 0; i < (int) tree.size() && !found; i++)
            if (!isNull(i))
                if (targetElement == tree[i]) {   // Java: targetElement.equals(tree[i])
                    found = true;
                    temp = tree[i];
                }

        if (!found)
            throw ElementNotFoundException("ArrayBinaryTree");

        return temp;
    }

    // Returns a string representation showing the nodes inorder.
    std::string toString() override {
        ArrayUnorderedList<T> tempList;
        inOrder(0, tempList);

        // Java built the text by iterating the list; we do the same. The
        // ArrayList stub toString() returns "", so we format here instead,
        // matching how the linked trees print their elements.
        std::string ret = "";
        for (T element : tempList)
            ret += elementToString(element) + " ";
        return ret;
    }

protected:
    // Recursive inorder traversal.
    void inOrder(int node, ArrayUnorderedList<T>& tempList) {
        if (node < (int) tree.size())
            if (!isNull(node)) {
                inOrder(node * 2 + 1, tempList);
                tempList.addToRear(tree[node]);
                inOrder((node + 1) * 2, tempList);
            }
    }

    // Recursive preorder traversal.
    void preOrder(int node, ArrayUnorderedList<T>& tempList) {
        if (node < (int) tree.size())
            if (!isNull(node)) {
                tempList.addToRear(tree[node]);
                preOrder(node * 2 + 1, tempList);
                preOrder((node + 1) * 2, tempList);
            }
    }

    // Recursive postorder traversal.
    void postOrder(int node, ArrayUnorderedList<T>& tempList) {
        if (node < (int) tree.size())
            if (!isNull(node)) {
                postOrder(node * 2 + 1, tempList);
                postOrder((node + 1) * 2, tempList);
                tempList.addToRear(tree[node]);
            }
    }
};

#endif
