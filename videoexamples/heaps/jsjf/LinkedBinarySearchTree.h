#ifndef LINKEDBINARYSEARCHTREE_H
#define LINKEDBINARYSEARCHTREE_H

#include "LinkedBinaryTree.h"
#include "BinarySearchTreeADT.h"
#include "BinaryTreeNode.h"
#include "exceptions/ElementNotFoundException.h"
#include "exceptions/EmptyCollectionException.h"
#include "exceptions/NonComparableElementException.h"

// LinkedBinarySearchTree implements the BinarySearchTreeADT interface with
// links.
//
// HEADER-ONLY TEMPLATE (mirrors the Java generic class).
//
// Java was "extends LinkedBinaryTree<T> implements BinarySearchTreeADT<T>".
// Comparable's compareTo becomes operator< / operator== . The Java
// "instanceof Comparable" runtime checks are dropped: C++ templates are
// duck-typed, so a type lacking operator< simply fails to compile.
//
// MEMORY: the remove* methods detach a node from the tree (Java relied on the
// GC). Before deleting that single node in C++ we first null its child
// pointers, so BinaryTreeNode's recursive destructor does NOT also delete the
// children that were rewired back into the tree.
template <typename T>
class LinkedBinarySearchTree : public LinkedBinaryTree<T>, public BinarySearchTreeADT<T> {
private:
    // Detaches children and deletes a single node (no subtree deletion).
    void deleteNode(BinaryTreeNode<T>* node) {
        if (node == nullptr) return;
        node->left = nullptr;
        node->right = nullptr;
        delete node;
    }

public:
    // Creates an empty binary search tree.
    LinkedBinarySearchTree() : LinkedBinaryTree<T>() {}

    // Creates a binary search tree with the specified element as its root.
    LinkedBinarySearchTree(T element) : LinkedBinaryTree<T>(element) {
        // Java threw NonComparableElementException if !(element instanceof
        // Comparable). C++ has no such runtime check (templates are duck-typed).
    }

    // Adds the specified object in its proper position (equal elements go
    // right).
    void addElement(T element) override {
        // Java: NonComparableElementException check omitted (duck-typed).

        if (this->isEmpty())
            this->root = new BinaryTreeNode<T>(element);
        else {
            if (element < this->root->getElement()) {   // Java: compareTo(...) < 0
                if (this->root->getLeft() == nullptr)
                    this->getRootNode()->setLeft(new BinaryTreeNode<T>(element));
                else
                    addElement(element, this->root->getLeft());
            }
            else {
                if (this->root->getRight() == nullptr)
                    this->getRootNode()->setRight(new BinaryTreeNode<T>(element));
                else
                    addElement(element, this->root->getRight());
            }
        }
        this->modCount++;
    }

private:
    // Recursive helper for addElement.
    void addElement(T element, BinaryTreeNode<T>* node) {
        if (element < node->getElement()) {
            if (node->getLeft() == nullptr)
                node->setLeft(new BinaryTreeNode<T>(element));
            else
                addElement(element, node->getLeft());
        }
        else {
            if (node->getRight() == nullptr)
                node->setRight(new BinaryTreeNode<T>(element));
            else
                addElement(element, node->getRight());
        }
    }

public:
    // Removes and returns the first element matching targetElement.
    T removeElement(T targetElement) override {
        T result = T();

        if (this->isEmpty())
            throw ElementNotFoundException("LinkedBinarySearchTree");
        else {
            BinaryTreeNode<T>* parent = nullptr;
            if (targetElement == this->root->element) {   // Java: equals
                result = this->root->element;
                BinaryTreeNode<T>* old = this->root;
                BinaryTreeNode<T>* temp = replacement(this->root);
                if (temp == nullptr)
                    this->root = nullptr;
                else {
                    this->root->element = temp->element;
                    this->root->setRight(temp->right);
                    this->root->setLeft(temp->left);
                    // temp's slot is now duplicated into root; free the
                    // (now-detached) temp node only. (Java: GC.)
                    deleteNode(temp);
                    old = nullptr;   // root reused, nothing extra to free
                }
                if (old != nullptr)
                    deleteNode(old);   // removed the only/childless root

                this->modCount++;
            }
            else {
                parent = this->root;
                if (targetElement < this->root->element)
                    result = removeElement(targetElement, this->root->getLeft(), parent);
                else
                    result = removeElement(targetElement, this->root->getRight(), parent);
            }
        }

        return result;
    }

private:
    // Recursive helper for removeElement.
    T removeElement(T targetElement, BinaryTreeNode<T>* node, BinaryTreeNode<T>* parent) {
        T result = T();

        if (node == nullptr)
            throw ElementNotFoundException("LinkedBinarySearchTree");
        else {
            if (targetElement == node->element) {   // Java: equals
                result = node->element;
                BinaryTreeNode<T>* temp = replacement(node);
                if (parent->right == node)
                    parent->right = temp;
                else
                    parent->left = temp;

                deleteNode(node);   // C++: free the removed node (Java: GC)

                this->modCount++;
            }
            else {
                parent = node;
                if (targetElement < node->element)
                    result = removeElement(targetElement, node->getLeft(), parent);
                else
                    result = removeElement(targetElement, node->getRight(), parent);
            }
        }

        return result;
    }

    // Returns the node that will replace the one specified for removal. With
    // two children, the inorder successor is used.
    BinaryTreeNode<T>* replacement(BinaryTreeNode<T>* node) {
        BinaryTreeNode<T>* result = nullptr;

        if ((node->left == nullptr) && (node->right == nullptr))
            result = nullptr;

        else if ((node->left != nullptr) && (node->right == nullptr))
            result = node->left;

        else if ((node->left == nullptr) && (node->right != nullptr))
            result = node->right;

        else {
            BinaryTreeNode<T>* current = node->right;
            BinaryTreeNode<T>* parent = node;

            while (current->left != nullptr) {
                parent = current;
                current = current->left;
            }

            current->left = node->left;
            if (node->right != current) {
                parent->left = current->right;
                current->right = node->right;
            }

            result = current;
        }

        return result;
    }

public:
    // Removes all occurrences of the specified element.
    void removeAllOccurrences(T targetElement) override {
        removeElement(targetElement);

        try {
            while (true) {
                removeElement(targetElement);
            }
        }
        catch (...) {   // Java caught ElementNotFoundException
        }
    }

    // Removes and returns the node with the least value.
    T removeMin() override {
        T result = T();

        if (this->isEmpty())
            throw EmptyCollectionException("LinkedBinarySearchTree");
        else {
            if (this->root->left == nullptr) {
                result = this->root->element;
                BinaryTreeNode<T>* old = this->root;
                this->root = this->root->right;
                deleteNode(old);   // C++: free detached node (Java: GC)
            }
            else {
                BinaryTreeNode<T>* parent = this->root;
                BinaryTreeNode<T>* current = this->root->left;
                while (current->left != nullptr) {
                    parent = current;
                    current = current->left;
                }
                result = current->element;
                parent->left = current->right;
                deleteNode(current);
            }

            this->modCount++;
        }

        return result;
    }

    // Removes and returns the node with the highest value.
    T removeMax() override {
        T result = T();

        if (this->isEmpty())
            throw EmptyCollectionException("LinkedBinarySearchTree");
        else {
            if (this->root->right == nullptr) {
                result = this->root->element;
                BinaryTreeNode<T>* old = this->root;
                this->root = this->root->left;
                deleteNode(old);
            }
            else {
                BinaryTreeNode<T>* parent = this->root;
                BinaryTreeNode<T>* current = this->root->right;
                while (current->right != nullptr) {
                    parent = current;
                    current = current->right;
                }
                result = current->element;
                parent->right = current->left;
                deleteNode(current);
            }

            this->modCount++;
        }

        return result;
    }

    // Returns the element with the least value (does not remove it).
    T findMin() override {
        if (this->isEmpty())
            throw EmptyCollectionException("LinkedBinarySearchTree");

        BinaryTreeNode<T>* current = this->root;

        while (current->getLeft() != nullptr) {
            current = current->getLeft();
        }

        return current->getElement();
    }

    // Returns the element matching targetElement (does not remove it).
    T find(T targetElement) override {
        T result = T();

        if (this->isEmpty())
            throw EmptyCollectionException("LinkedBinarySearchTree");

        BinaryTreeNode<T>* resultNode = findNode(targetElement, this->root);

        if (resultNode == nullptr) {
            throw ElementNotFoundException("LinkedBinarySearchTree");
        }
        else {
            result = resultNode->getElement();
        }

        return result;
    }

private:
    // BST-specific recursive find (uses ordering).
    BinaryTreeNode<T>* findNode(T targetElement, BinaryTreeNode<T>* next) {
        BinaryTreeNode<T>* result = nullptr;

        if (next == nullptr) {
            result = nullptr;
        }
        else if (targetElement == next->getElement()) {   // Java: compareTo(...) == 0
            result = next;
        }
        else if (targetElement < next->getElement()) {    // Java: compareTo(...) < 0
            result = findNode(targetElement, next->getLeft());
        }
        else {
            result = findNode(targetElement, next->getRight());
        }

        return result;
    }

public:
    // Returns the element with the highest value (does not remove it).
    T findMax() override {
        if (this->isEmpty())
            throw EmptyCollectionException("LinkedBinarySearchTree");

        BinaryTreeNode<T>* current = this->root;

        while (current->getRight() != nullptr) {
            current = current->getRight();
        }

        return current->getElement();
    }

    // Returns the left subtree of the root (a non-owning view).
    LinkedBinarySearchTree<T> getLeft() {
        if (this->isEmpty())
            throw EmptyCollectionException("LinkedBinarySearchTree");

        LinkedBinarySearchTree<T> ret;
        ret.root = this->root->getLeft();
        ret.ownsNodes = false;   // shares nodes; must not free
        return ret;
    }

    // Returns the right subtree of the root (a non-owning view).
    LinkedBinarySearchTree<T> getRight() {
        if (this->isEmpty())
            throw EmptyCollectionException("LinkedBinarySearchTree");

        LinkedBinarySearchTree<T> ret;
        ret.root = this->root->getRight();
        ret.ownsNodes = false;
        return ret;
    }

    // ----------------------------------------------------------------------
    // Disambiguate methods declared pure in both BinaryTreeADT bases (via
    // LinkedBinaryTree and via BinarySearchTreeADT). Forward to the
    // LinkedBinaryTree implementations.
    // ----------------------------------------------------------------------
    bool isEmpty() override { return LinkedBinaryTree<T>::isEmpty(); }
    int size() override { return LinkedBinaryTree<T>::size(); }
    bool contains(T t) override { return LinkedBinaryTree<T>::contains(t); }
    T getRootElement() override { return LinkedBinaryTree<T>::getRootElement(); }
    std::string toString() override { return LinkedBinaryTree<T>::toString(); }
};

#endif
