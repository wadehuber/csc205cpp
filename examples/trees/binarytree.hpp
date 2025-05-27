#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "TreeNode.h"

class BinaryTree {
protected:
    TreeNode* root;

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree();

    bool isEmpty() const { return root == nullptr; }
    TreeNode* getRoot() const { return root; }
    
    void clear();
    void preOrderTraversal() const;
    void inOrderTraversal() const;
    void postOrderTraversal() const;

private:
    void clear(TreeNode* node);
    void preOrder(TreeNode* node) const;
    void inOrder(TreeNode* node) const;
    void postOrder(TreeNode* node) const;
};