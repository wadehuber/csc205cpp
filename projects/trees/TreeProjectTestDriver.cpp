// TreeProjectTestDriver -- C++ conversion of TreeProjectTestDriver.java
//
// Exercises the (partly student-stubbed) LinkedBinarySearchTree, the stubbed
// LinkedBSTOrderedSet, and the stubbed Sorting::bstSort. Because several BST
// methods are PROGRAMMING-PROJECT STUBS, their output reflects the unfinished
// starter code exactly (e.g. find/findMin/findMax/removeMax return the default
// value 0 for int and do nothing, and bstSort leaves arrays unsorted).
//
// In Java, Integer objects printed via toString(). Here T = int, so we print
// ints directly. Java's null printed as "null"; the stubs here return a
// default int (0), and the driver prints that 0 just as the int default.

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>   // std::rand, std::srand
#include <ctime>     // std::time

#include "csc205/Sorting.h"
#include "jsjf/LinkedBSTOrderedSet.h"
#include "jsjf/LinkedBinarySearchTree.h"
#include "jsjf/exceptions/ElementNotFoundException.h"

// Helper methods (forward declarations) -----------------------------------
std::vector<int> generateRandomArray(int len);
void printArray(std::vector<int>& a);

int main() {
    // Seed the random generator. Java's Math.random() / Random are seeded from
    // the clock; we do the same so each run differs (matching Java behavior).
    std::srand((unsigned) std::time(nullptr));

    LinkedBinarySearchTree<int> t;
    LinkedBSTOrderedSet<int> o;

    // Set up test data
    for (int ii = 0; ii < 30; ii++) {
        int num = (int) ((std::rand() / (double) RAND_MAX) * 10);  // Java: (int)(Math.random()*10)
        t.addElement(num);    // BinarySearchTree
        o.addElement(num);    // LinkedBSTOrderedSet
    }

    std::cout << "Binary Search Tree (" << t.size() << "): " << t.toString() << std::endl;
    std::cout << "\nFind:" << std::endl;

    for (int jj = 0; jj < 4; jj++) {
        try {
            // find() is a stub: it never throws and returns the default int 0.
            int res = t.find(jj * 4 + 1);
            std::cout << "  Found " << (jj * 4 + 1) << ": " << res << std::endl;
        }
        catch (const ElementNotFoundException& e) {
            std::cout << "  Did not find " << (jj * 4 + 1) << std::endl;
        }
    }

    std::cout << "BST min: " << t.findMin() << std::endl;       // stub -> 0
    std::cout << "BST max: " << t.findMax() << std::endl;       // stub -> 0
    std::cout << "BST remove min: " << t.removeMin() << std::endl;  // implemented
    std::cout << "BST remove max: " << t.removeMax() << std::endl;  // stub -> 0, no removal
    std::cout << "Removing 3 min, 3 max" << std::endl;
    t.removeMin();
    t.removeMax();
    t.removeMax();
    t.removeMin();
    t.removeMax();
    t.removeMin();
    std::cout << "Binary Search Tree (" << t.size() << "): " << t.toString() << std::endl;

    std::cout << "\nIn-Order: ";
    // Java used an Iterator; here iteratorInOrder() returns a list we walk.
    for (int element : t.iteratorInOrder()) {
        std::cout << element << " ";
    }

    std::cout << "\nPost-Order: ";
    for (int element : t.iteratorPostOrder()) {
        std::cout << element << " ";
    }

    std::cout << "\n\nOrdered Set: " << o.toString() << std::endl;

    std::cout << "\nbstSort Testing:" << std::endl;
    std::vector<std::vector<int>> testArray;
    std::vector<int> a1 = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    std::vector<int> a2 = {11, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> a3 = generateRandomArray(10);
    testArray.push_back(a1);
    testArray.push_back(a2);
    testArray.push_back(a3);

    int count = 0;
    for (std::vector<int>& ta : testArray) {
        count++;
        Sorting::bstSort(ta);   // stub: leaves array unchanged
        if (Sorting::isSorted(ta)) {
            std::cout << "    Array" << count << ": ";
            printArray(ta);
        }
        else {
            std::cout << "    SORTING FAILED FOR ARRAY " << count << std::endl;
        }
    }

    std::cout << "\nprintTree Testing: " << std::endl;
    std::cout << "    t: ";
    t.printTree();
    LinkedBinarySearchTree<int> bst;
    bst.addElement(5);
    bst.addElement(3);
    bst.addElement(2);
    bst.addElement(4);
    bst.addElement(7);
    std::cout << "    bst: ";
    bst.printTree();
    std::cout << "DONE with Project 8 Testing" << std::endl;

    return 0;
}

// Helper methods ----------------------------------------------------------

// Returns an array (vector) of 'len' random ints in [0, 1000).
std::vector<int> generateRandomArray(int len) {
    std::vector<int> a(len);

    for (int ii = 0; ii < (int) a.size(); ii++) {
        a[ii] = std::rand() % 1000;   // Java: rand.nextInt(1000)
    }
    return a;
}

void printArray(std::vector<int>& a) {
    for (int ii = 0; ii < (int) a.size(); ii++) {
        std::cout << a[ii] << " ";
    }
    std::cout << std::endl;
}
