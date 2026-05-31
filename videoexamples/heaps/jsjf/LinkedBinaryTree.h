#ifndef LINKEDBINARYTREE_H
#define LINKEDBINARYTREE_H

#include <string>
#include <algorithm>   // std::max
#include "BinaryTreeADT.h"
#include "BinaryTreeNode.h"
#include "ArrayUnorderedList.h"
#include "ElementToString.h"
#include "exceptions/ElementNotFoundException.h"
#include "exceptions/EmptyCollectionException.h"

// LinkedBinaryTree implements the BinaryTreeADT interface.
//
// HEADER-ONLY TEMPLATE (mirrors the Java generic class).
//
// MEMORY: nodes are raw pointers created with new (just like Java's new), and
// nullptr replaces null. Java's garbage collector freed nodes automatically;
// in C++ we must do it ourselves. The destructor deletes 'root', and
// BinaryTreeNode's destructor recursively deletes its children, so the whole
// tree is freed with no leaks.
//
// OWNERSHIP NOTE: getLeft()/getRight()/printTree() build temporary
// LinkedBinaryTree "views" whose root points INTO an existing tree (the nodes
// are shared, exactly as in Java). Such a view must NOT delete those shared
// nodes, or we would double-free. We track this with 'ownsNodes': a normal
// tree owns its nodes; a view does not. (Java did not need this because the GC
// only frees nodes when nothing references them.)
template <typename T>
class LinkedBinaryTree : public virtual BinaryTreeADT<T> {   // virtual: shared base in the diamond
protected:
    BinaryTreeNode<T>* root;
    int modCount;
    bool ownsNodes;   // C++-only: false for getLeft()/getRight() views

public:
    // Creates an empty binary tree.
    LinkedBinaryTree() {
        root = nullptr;
        modCount = 0;
        ownsNodes = true;
    }

    // Creates a binary tree with the specified element as its root.
    LinkedBinaryTree(T element) {
        root = new BinaryTreeNode<T>(element);
        modCount = 0;
        ownsNodes = true;
    }

    // C++ needs an explicit destructor (Java's GC did this). Deletes the
    // whole tree unless this object is only a non-owning view.
    virtual ~LinkedBinaryTree() {
        if (ownsNodes)
            delete root;   // recursively deletes all descendant nodes
    }

    // Returns a reference to the element at the root.
    T getRootElement() override {
        if (root == nullptr)
            throw EmptyCollectionException("LinkedBinaryTree");

        return root->getElement();
    }

protected:
    // Returns a reference to the node at the root.
    BinaryTreeNode<T>* getRootNode() {
        if (root == nullptr)
            throw EmptyCollectionException("LinkedBinaryTree");

        return root;
    }

public:
    // Returns the left subtree of the root of this tree (a non-owning view).
    LinkedBinaryTree<T> getLeft() {
        if (root == nullptr)
            throw EmptyCollectionException("LinkedBinaryTree - getLeft() -");

        LinkedBinaryTree<T> result;
        result.root = root->getLeft();
        result.ownsNodes = false;   // shares nodes with this tree; must not free

        return result;
    }

    // Returns the right subtree of the root of this tree (a non-owning view).
    LinkedBinaryTree<T> getRight() {
        if (root == nullptr)
            throw EmptyCollectionException("LinkedBinaryTree - getRight() -");

        LinkedBinaryTree<T> result;
        result.root = root->getRight();
        result.ownsNodes = false;

        return result;
    }

    // Returns true if this binary tree is empty and false otherwise.
    bool isEmpty() override {
        return (root == nullptr);
    }

    // Returns the integer size of this tree.
    int size() override {
        if (root == nullptr)
            return 0;

        return root->numChildren() + 1;
    }

    // Returns the height of this tree.
    int getHeight() {
        return height(root) - 1;
    }

private:
    // Returns the height of the specified node.
    int height(BinaryTreeNode<T>* node) {
        int result = 0;
        if (node != nullptr)
            result = std::max(height(node->getLeft()), height(node->getRight())) + 1;

        return result;
    }

public:
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
        BinaryTreeNode<T>* current = findNode(targetElement, root);

        if (current == nullptr)
            throw ElementNotFoundException("LinkedBinaryTree");

        return current->getElement();
    }

protected:
    // Recursive helper for find.
    BinaryTreeNode<T>* findNode(T targetElement, BinaryTreeNode<T>* next) {
        if (next == nullptr)
            return nullptr;

        if (next->getElement() == targetElement)   // Java: equals
            return next;

        BinaryTreeNode<T>* temp = findNode(targetElement, next->getLeft());

        if (temp == nullptr)
            temp = findNode(targetElement, next->getRight());

        return temp;
    }

public:
    // Returns a string representation showing the nodes inorder.
    std::string toString() override {
        ArrayUnorderedList<T> tempList;
        inOrder(root, tempList);

        std::string ret = "";

        for (T element : tempList) {
            ret += elementToString(element) + " ";   // Java: element.toString()
        }

        return ret;
    }

protected:
    // Recursive inorder traversal.
    void inOrder(BinaryTreeNode<T>* node, ArrayUnorderedList<T>& tempList) {
        if (node != nullptr) {
            inOrder(node->getLeft(), tempList);
            tempList.addToRear(node->getElement());
            inOrder(node->getRight(), tempList);
        }
    }

    // Recursive preorder traversal.
    void preOrder(BinaryTreeNode<T>* node, ArrayUnorderedList<T>& tempList) {
        if (node != nullptr) {
            tempList.addToRear(node->getElement());
            preOrder(node->getLeft(), tempList);
            preOrder(node->getRight(), tempList);
        }
    }

    // Recursive postorder traversal.
    void postOrder(BinaryTreeNode<T>* node, ArrayUnorderedList<T>& tempList) {
        if (node != nullptr) {
            postOrder(node->getLeft(), tempList);
            postOrder(node->getRight(), tempList);
            tempList.addToRear(node->getElement());
        }
    }

public:
    // Returns a recursive string representation of a tree.
    std::string printTree() {
        LinkedBinaryTree<T> theRoot;
        theRoot.root = root;
        theRoot.ownsNodes = false;   // view; do not free shared nodes
        return returnRecursiveString(theRoot);
    }

private:
    std::string returnRecursiveString(LinkedBinaryTree<T> curr) {
        std::string ret = "";
        if (!(curr.isEmpty())) {
            ret = "(";
            if (curr.getLeft().root != nullptr) {
                ret += returnRecursiveString(curr.getLeft()) + " ";
            }
            // Java concatenated curr.getRootElement() directly; we call
            // toString() explicitly. (For int this would need a helper, but
            // printTree() is not used by any driver in this package.)
            ret += elementToString(curr.getRootElement());
            if (curr.getRight().root != nullptr) {
                ret += " " + returnRecursiveString(curr.getRight());
            }
            ret += ")";
        }
        return ret;
    }
};

#endif
