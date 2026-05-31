// Driver that exercises the jsjf array-based ordered and unordered lists.
//
// Java declared the variables with the ADT (interface) types and assigned
// concrete ArrayOrderedList / ArrayUnorderedList objects. In C++ we use base
// pointers (OrderedListADT<int>* / UnorderedListADT<int>*) to the same effect,
// "new" the concrete lists, and delete them at the end.
//
// RANDOM NOTE: Java used java.util.Random and gen.nextInt(100). C++ uses
// <random> (mt19937 + uniform_int_distribution 0..99). Because the numbers are
// random, the exact values differ from run to run (this was true in Java too).
// What is deterministic is the LOGIC: orderedList comes out sorted ascending,
// unorderedList1 is the reverse of the insertion order (addToFront), and
// unorderedList2 is in insertion order (addToRear).

#include <iostream>
#include <random>

#include "jsjf/OrderedListADT.h"
#include "jsjf/UnorderedListADT.h"
#include "jsjf/ArrayOrderedList.h"
#include "jsjf/ArrayUnorderedList.h"

int main() {
    OrderedListADT<int>* orderedList = new ArrayOrderedList<int>(2);
    UnorderedListADT<int>* unorderedList1 = new ArrayUnorderedList<int>(2);
    UnorderedListADT<int>* unorderedList2 = new ArrayUnorderedList<int>(2);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 99);   // gen.nextInt(100)

    for (int ii = 0; ii < 10; ii++) {
        int num = dist(gen);
        orderedList->add(num);
        unorderedList1->addToFront(num);
        unorderedList2->addToRear(num);
    }

    std::cout << "OrderedList [" << orderedList->size() << "]: " << orderedList->toString() << std::endl;
    std::cout << "UnorderedList1 [" << unorderedList1->size() << "]: " << unorderedList1->toString() << std::endl;
    std::cout << "UnorderedList2 [" << unorderedList2->size() << "]: " << unorderedList2->toString() << std::endl;

    // C++ has no garbage collector, so free what we "new"ed.
    delete orderedList;
    delete unorderedList1;
    delete unorderedList2;

    return 0;
}
