#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H

// BinaryTreeNode represents a node in a binary tree with a left and right
// child.
//
// HEADER-ONLY TEMPLATE (mirrors the Java generic class).
//
// MEMORY: in Java these nodes were created with 'new' and reclaimed by the
// garbage collector. In C++ we use RAW POINTERS + new + nullptr to mirror the
// Java structure exactly, and we must delete them ourselves. The destructor
// below recursively deletes the left and right children, so deleting the root
// of a tree frees the entire tree (no leaks). We deliberately do NOT delete a
// parent pointer (see HeapNode) -- a child does not own its parent, and the
// parent owns the child, so deleting parents here would double-free.
template <typename T>
class BinaryTreeNode {
public:
    T element;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    // Creates a new tree node with the specified data.
    BinaryTreeNode(T obj) {
        element = obj;
        left = nullptr;
        right = nullptr;
    }

    // C++ needs an explicit destructor (Java's GC did this automatically).
    // Recursively deletes children, freeing the whole subtree rooted here.
    // virtual so deleting through a BinaryTreeNode<T>* also runs the derived
    // HeapNode destructor.
    virtual ~BinaryTreeNode() {
        delete left;
        delete right;
    }

    // NOTE: Java also had a constructor
    //   BinaryTreeNode(T obj, LinkedBinaryTree<T> left, LinkedBinaryTree<T> right)
    // It is unused by every driver in this package, and pulling it in would
    // create a circular dependency with LinkedBinaryTree, so it is omitted.

    // Returns the number of non-null children of this node.
    int numChildren() {
        int children = 0;

        if (left != nullptr)
            children = 1 + left->numChildren();

        if (right != nullptr)
            children = children + 1 + right->numChildren();

        return children;
    }

    // Return true if this node is a leaf and false otherwise.
    bool isLeaf() {
        return (numChildren() == 0);
    }

    // Return the element at this node.
    T getElement() { return element; }

    // Return the right child of this node.
    BinaryTreeNode<T>* getRight() { return right; }

    // Sets the right child of this node.
    void setRight(BinaryTreeNode<T>* node) { right = node; }

    // Return the left child of this node.
    BinaryTreeNode<T>* getLeft() { return left; }

    // Sets the left child of this node.
    void setLeft(BinaryTreeNode<T>* node) { left = node; }
};

#endif
