// SortPhoneList driver for testing a heap sort.
//
// Translated from SortPhoneList.java. Creates an array of Contact objects,
// sorts them with Sorting::heapSort, then prints them.

#include <iostream>
#include "Contact.h"
#include "csc205/Sorting.h"

int main() {
    Contact friends[7] = {
        Contact("John",   "Smith",  "610-555-7384"),
        Contact("Sarah",  "Barnes", "215-555-3827"),
        Contact("Mark",   "Riley",  "733-555-2969"),
        Contact("Laura",  "Getz",   "663-555-3984"),
        Contact("Larry",  "Smith",  "464-555-3489"),
        Contact("Frank",  "Phelps", "322-555-2284"),
        Contact("Marsha", "Grant",  "243-555-2837")
    };

    Sorting::heapSort(friends);

    // Java: for (Contact friend : friends) System.out.println(friend);
    for (const Contact& friendContact : friends)
        std::cout << friendContact.toString() << std::endl;

    return 0;
}
