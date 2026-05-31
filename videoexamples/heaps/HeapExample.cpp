// HeapExample - example of using a Heap (and a binary search tree).
//
// Driver translated from HeapExample.java. Builds an int minheap, an int
// binary search tree, and a StudentRecord minheap, prints them, then removes
// the four smallest elements from two of them.

#include <iostream>
#include <random>
#include "jsjf/LinkedBinarySearchTree.h"
#include "jsjf/LinkedBinaryTree.h"
#include "jsjf/LinkedHeap.h"
#include "StudentRecord.h"

int main() {
    LinkedHeap<int> t;
    LinkedHeap<StudentRecord> s;
    LinkedBinarySearchTree<int> k;

    // Java used Math.random()*100 to get an int in [0, 99]. We do the same
    // with C++'s <random>. NOTE: like the Java program, the int heap/tree
    // contents are RANDOM, so the "Tree k" and "Heap t" lines differ from run
    // to run (and from the Java run). The StudentRecord output below is
    // deterministic and matches Java exactly.
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 99);

    for (int ii = 0; ii < 20; ii++) {
        int num = dist(gen);
        t.addElement(num);
        k.addElement(num);
    }

    s.addElement(StudentRecord("Harrison Ford", 3.5));
    s.addElement(StudentRecord("Mark Hamil", 3.1));
    s.addElement(StudentRecord("Carrie Fisher", 3.1));
    s.addElement(StudentRecord("Adam Driver", 3.8));
    s.addElement(StudentRecord("Daisy Ridley", 3.3));
    s.addElement(StudentRecord("John Boyega", 3.3));
    s.addElement(StudentRecord("Oscar Isaac", 3.3));
    s.addElement(StudentRecord("Lupita Nyong'o", 3.9));
    s.addElement(StudentRecord("Andy Serkis", 3.3));
    s.addElement(StudentRecord("Domhnall Gleeson", 3.4));

    std::cout << "Tree k: " << k.toString() << std::endl;
    std::cout << "Heap t: " << t.toString() << std::endl;
    std::cout << "Heap s: " << s.toString() << std::endl;

    std::cout << "\nremoveMin testing s:" << std::endl;
    for (int x = 0; x < 4; x++) {
        std::cout << s.removeMin().toString() << std::endl;
    }

    std::cout << "\nremoveMin testing t:" << std::endl;
    for (int x = 0; x < 4; x++) {
        std::cout << t.removeMin() << std::endl;
    }

    return 0;
}
