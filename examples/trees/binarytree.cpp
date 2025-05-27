// BinaryTree.cpp
#include "BinaryTree.h"

BinaryTree::~BinaryTree() {
    clear();
}

void BinaryTree::clear() {
    clear(root);
    root = nullptr;
}

void BinaryTree::clear(TreeNode* node) {
    if (node != nullptr) {
        clear(node->getLeft());
        clear(node->getRight());
        delete node;
    }
}

void BinaryTree::preOrderTraversal() const {
    preOrder(root);
}

void BinaryTree::inOrderTraversal() const {
    inOrder(root);
}

void BinaryTree::postOrderTraversal() const {
    postOrder(root);
}

void BinaryTree::preOrder(TreeNode* node) const {
    if (node != nullptr) {
        std::cout << node->getData() << " ";
        preOrder(node->getLeft());
        preOrder(node->getRight());
    }
}

void BinaryTree::inOrder(TreeNode* node) const {
    if (node != nullptr) {
        inOrder(node->getLeft());
        std::cout << node->getData() << " ";
        inOrder(node->getRight());
    }
}

void BinaryTree::postOrder(TreeNode* node) const {
    if (node != nullptr) {
        postOrder(node->getLeft());
        postOrder(node->getRight());
        std::cout << node->getData() << " ";
    }
}

#endif