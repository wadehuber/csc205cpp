#include <string>
#include <cmath>
#include <memory>
#include <list>

// Forward declarations
template<typename T>
class BinaryTreeNode;

template<typename T>
class LinkedBinaryTree;

class ExpressionTreeOp {
private:
    bool isOp;
    char op;
    int val;

public:
    ExpressionTreeOp(char op) : isOp(true), op(op), val(0) {}
    ExpressionTreeOp(int value) : isOp(false), op('\0'), val(value) {}

    bool isOperator() const { return isOp; }
    char getOperator() const { return op; }
    int getValue() const { return val; }

    std::string toString() const {
        if (isOp) {
            return std::string(1, op);
        }
        return std::to_string(val);
    }
};

template<typename T>
class BinaryTreeNode {
private:
    T element;
    std::shared_ptr<BinaryTreeNode<T>> left;
    std::shared_ptr<BinaryTreeNode<T>> right;

public:
    BinaryTreeNode(const T& elem) : element(elem), left(nullptr), right(nullptr) {}
    
    BinaryTreeNode(const T& elem, 
                   std::shared_ptr<BinaryTreeNode<T>> leftTree,
                   std::shared_ptr<BinaryTreeNode<T>> rightTree)
        : element(elem), left(leftTree), right(rightTree) {}

    T getElement() const { return element; }
    std::shared_ptr<BinaryTreeNode<T>> getLeft() const { return left; }
    std::shared_ptr<BinaryTreeNode<T>> getRight() const { return right; }

    void setElement(const T& elem) { element = elem; }
    void setLeft(std::shared_ptr<BinaryTreeNode<T>> leftTree) { left = leftTree; }
    void setRight(std::shared_ptr<BinaryTreeNode<T>> rightTree) { right = rightTree; }
};

class ExpressionTree {
private:
    std::shared_ptr<BinaryTreeNode<ExpressionTreeOp>> root;

    // Helper method to compute terms
    static int computeTerm(char op, int operand1, int operand2) {
        switch(op) {
            case '+': return operand1 + operand2;
            case '-': return operand1 - operand2;
            case '*': return operand1 * operand2;
            case '/': return operand1 / operand2;
            default: return 0;
        }
    }

    int evaluateNode(std::shared_ptr<BinaryTreeNode<ExpressionTreeOp>> node) {
        if (!node) {
            return 0;
        }

        ExpressionTreeOp temp = node->getElement();

        if (temp.isOperator()) {
            int operand1 = evaluateNode(node->getLeft());
            int operand2 = evaluateNode(node->getRight());
            return computeTerm(temp.getOperator(), operand1, operand2);
        } else {
            return temp.getValue();
        }
    }

    int getHeight(std::shared_ptr<BinaryTreeNode<ExpressionTreeOp>> node) const {
        if (!node) {
            return -1;
        }
        return 1 + std::max(getHeight(node->getLeft()), getHeight(node->getRight()));
    }

public:
    ExpressionTree() : root(nullptr) {}

    ExpressionTree(const ExpressionTreeOp& element,
                  const ExpressionTree& leftSubtree,
                  const ExpressionTree& rightSubtree) {
        root = std::make_shared<BinaryTreeNode<ExpressionTreeOp>>(
            element,
            leftSubtree.root,
            rightSubtree.root
        );
    }

    int evaluateTree() {
        return evaluateNode(root);
    }

    int getHeight() const {
        return getHeight(root);
    }

    std::string printTree() {
        if (!root) {
            return "";
        }

        std::list<std::shared_ptr<BinaryTreeNode<ExpressionTreeOp>>> nodes;
        std::list<int> levelList;
        std::string result;

        int printDepth = getHeight();
        int possibleNodes = static_cast<int>(std::pow(2, printDepth + 1));
        int countNodes = 0;

        nodes.push_back(root);
        levelList.push_back(0);
        int previousLevel = -1;

        while (countNodes < possibleNodes) {
            countNodes++;
            auto current = nodes.front();
            nodes.pop_front();
            int currentLevel = levelList.front();
            levelList.pop_front();

            if (currentLevel > previousLevel) {
                result += "\n\n";
                previousLevel = currentLevel;
                for (int j = 0; j < static_cast<int>(std::pow(2, printDepth - currentLevel)) - 1; j++) {
                    result += " ";
                }
            } else {
                for (int i = 0; i < static_cast<int>(std::pow(2, printDepth - currentLevel + 1)) - 1; i++) {
                    result += " ";
                }
            }

            if (current) {
                result += current->getElement().toString();
                nodes.push_back(current->getLeft());
                levelList.push_back(currentLevel + 1);
                nodes.push_back(current->getRight());
                levelList.push_back(currentLevel + 1);
            } else {
                nodes.push_back(nullptr);
                levelList.push_back(currentLevel + 1);
                nodes.push_back(nullptr);
                levelList.push_back(currentLevel + 1);
                result += " ";
            }
        }

        return result;
    }
};
