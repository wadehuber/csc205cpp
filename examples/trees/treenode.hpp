#ifndef TREENODE_H
#define TREENODE_H

class TreeNode {
private:
    int data;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
    
    int getData() const { return data; }
    void setData(int value) { data = value; }
    
    TreeNode* getLeft() const { return left; }
    void setLeft(TreeNode* node) { left = node; }
    
    TreeNode* getRight() const { return right; }
    void setRight(TreeNode* node) { right = node; }
};

#endif