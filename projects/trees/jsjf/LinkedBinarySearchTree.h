#ifndef LINKEDBINARYSEARCHTREE_H
#define LINKEDBINARYSEARCHTREE_H

#include <string>
#include <iostream>
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
// Comparable's compareTo becomes operator< / operator==. The Java
// "instanceof Comparable" runtime checks are dropped: C++ templates are
// duck-typed, so a type lacking operator< simply fails to compile.
//
// *** PROGRAMMING-PROJECT STUBS ***
// This is the STUDENT-STARTER version of the class. Several methods are left
// as stubs in the Java source ("To be completed as a Programming Project",
// "return null; // temp"). We reproduce those stubs faithfully so the project
// compiles and behaves exactly like the unfinished Java starter code:
//   removeMax, findMin, find, findMax, getLeft, getRight, printTree.
// Java returned null for these; in C++ we return a default-constructed T()
// (or nullptr for a tree). DO NOT implement the project logic here.
//
// MEMORY: the implemented remove* methods detach a node from the tree (Java
// relied on the GC). Before deleting that single detached node in C++ we first
// null its child pointers, so BinaryTreeNode's recursive destructor does NOT
// also delete children that were rewired back into the tree.
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
        else
            addElement(element, this->root);
        this->modCount++;
    }

private:
    // Recursive helper for addElement.
    void addElement(T element, BinaryTreeNode<T>* node) {
        if (element < node->getElement()) {   // Java: compareTo(...) < 0
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
    // Removes the first element that matches targetElement and returns it.
    T removeElement(T targetElement) override {
        T result = T();   // Java: T result = null;

        if (this->isEmpty())
            throw ElementNotFoundException("LinkedBinarySearchTree");
        else {
            BinaryTreeNode<T>* parent = nullptr;
            if (targetElement == this->root->element) {   // Java: equals
                // Remove the root
                result = this->root->element;
                BinaryTreeNode<T>* inOrderSuccessor = replacement(this->root);
                if (inOrderSuccessor == nullptr) {
                    deleteNode(this->root);   // free the detached node
                    this->root = nullptr;
                }
                else {
                    this->root->element = inOrderSuccessor->element;
                    this->root->setRight(inOrderSuccessor->right);
                    this->root->setLeft(inOrderSuccessor->left);
                    deleteNode(inOrderSuccessor);   // its links were copied out
                }

                this->modCount++;
            }
            else {
                // Look for the target in a sub-tree
                parent = this->root;
                if (targetElement < this->root->element)   // Java: compareTo(...) < 0
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
        T result = T();   // Java: T result = null;

        if (node == nullptr)
            throw ElementNotFoundException("LinkedBinarySearchTree");
        else {
            if (targetElement == node->element) {   // Java: equals
                // remove the current node
                result = node->element;
                BinaryTreeNode<T>* inOrderSuccessor = replacement(node);
                // Decide if current node is left or right child of the parent
                if (parent->right == node)
                    parent->right = inOrderSuccessor;
                else
                    parent->left = inOrderSuccessor;

                deleteNode(node);   // free the detached node (its links moved)

                this->modCount++;
            }
            else {
                // Look for the target in a sub-tree
                parent = node;
                if (targetElement < node->element)   // Java: compareTo(...) < 0
                    result = removeElement(targetElement, node->getLeft(), parent);
                else
                    result = removeElement(targetElement, node->getRight(), parent);
            }
        }

        return result;
    }

    // Returns a reference to a node that will replace the one specified for
    // removal. When the removed node has two children, the inorder successor
    // is used as its replacement.
    BinaryTreeNode<T>* replacement(BinaryTreeNode<T>* root) {
        BinaryTreeNode<T>* result = nullptr;

        // No children
        if ((root->left == nullptr) && (root->right == nullptr))
            result = nullptr;

        // One child - left
        else if ((root->left != nullptr) && (root->right == nullptr))
            result = root->left;

        // One child - right
        else if ((root->left == nullptr) && (root->right != nullptr))
            result = root->right;

        else {
            BinaryTreeNode<T>* current = root->right;
            BinaryTreeNode<T>* parent = root;

            while (current->left != nullptr) {
                parent = current;
                current = current->left;
            }

            // Set the replacement's left subtree to the root's left subtree
            current->left = root->left;
            if (root->right != current) {
                parent->left = current->right;
                current->right = root->right;
            }

            result = current;
        }

        return result;
    }

public:
    // Removes all occurrences of the specified element from the tree.
    void removeAllOccurrences(T targetElement) override {
        removeElement(targetElement);

        try {
            while (this->contains(targetElement))
                removeElement(targetElement);
        }
        catch (...) {   // Java caught Exception
        }
    }

    // Removes the node with the least value and returns its element.
    T removeMin() override {
        T result = T();   // Java: T result = null;

        if (this->isEmpty())
            throw EmptyCollectionException("LinkedBinarySearchTree");
        else {
            if (this->root->left == nullptr) {
                // Root is the min element
                result = this->root->element;
                BinaryTreeNode<T>* oldRoot = this->root;
                this->root = this->root->right;
                deleteNode(oldRoot);   // free the detached old root
            }
            else {
                // Min element is all the way to the left
                BinaryTreeNode<T>* parent = this->root;
                BinaryTreeNode<T>* current = this->root->left;
                while (current->left != nullptr) {
                    parent = current;
                    current = current->left;
                }
                result = current->element;
                parent->left = current->right;
                deleteNode(current);   // free the detached min node
            }

            this->modCount++;
        }

        return result;
    }

    // Removes the node with the highest value and returns its element.
    T removeMax() override {
        // To be completed as a Programming Project
        // (Java returned null; in C++ we return a default-constructed T().)
        return T();   // temp
    }

    // Returns the element with the least value (does not remove it).
    T findMin() override {
        // To be completed as a Programming Project
        // (Java returned null; in C++ we return a default-constructed T().)
        return T();   // temp
    }

    // Returns the element that matches targetElement (does not remove it).
    T find(T targetElement) override {
        // To be completed as a Programming Project
        // (Java returned null; in C++ we return a default-constructed T().)
        (void) targetElement;   // unused in the stub
        return T();   // temp
    }

    // Returns the element with the highest value (does not remove it).
    T findMax() override {
        // To be completed as a Programming Project
        // (Java returned null; in C++ we return a default-constructed T().)
        return T();   // temp
    }

    // Returns the left subtree of the root of this tree.
    LinkedBinarySearchTree<T>* getLeft() {
        // To be completed as a Programming Project
        // (Java returned null; in C++ we return nullptr.)
        return nullptr;   // temp
    }

    // Returns the right subtree of the root of this tree.
    LinkedBinarySearchTree<T>* getRight() {
        // To be completed as a Programming Project
        // (Java returned null; in C++ we return nullptr.)
        return nullptr;   // temp
    }

    // Prints the tree (to be completed for project 8).
    void printTree() {
        // Complete for project 8
        std::cout << "Complete for project 8" << std::endl;
    }
};

#endif
