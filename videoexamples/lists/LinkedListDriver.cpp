// Driver that uses the csc205 LinkedList we implemented.
//
// Java printed objects directly (System.out.println(myList) and string
// concatenation like "First = " + myList.first()). In C++ we print
// myList.toString() explicitly and stream the (string) elements with <<.

#include <iostream>
#include <string>

#include "csc205/LinkedList.h"

int main() {
    LinkedList<std::string> myList;
    std::string searchValues[] = {"Hello", "World", "Arizona", "CGCC", "Chandler", "205"};
    const int searchCount = 6;

    myList.addToFront("World");
    myList.addToFront("Hello");
    myList.addToRear("Chandler");
    myList.addToRear("Gilbert");

    std::cout << myList.toString() << std::endl;

    std::cout << "Size = " << myList.size() << std::endl;
    std::cout << "First = " << myList.first() << std::endl;
    std::cout << "Last = " << myList.last() << std::endl;

    if (myList.isEmpty()) {
        std::cout << "List is empty" << std::endl;
    }
    else {
        std::cout << "List is not empty" << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Iterator test:" << std::endl;
    std::cout << "  ";
    for (const std::string& s : myList) {
        std::cout << s << " ";
    }
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "Contains testing (part 1):" << std::endl;
    for (int i = 0; i < searchCount; i++) {
        std::string val = searchValues[i];
        if (myList.contains(val)) {
            std::cout << "  myList contains " << val << " at index " << myList.indexOf(val) << std::endl;
        }
        else {
            std::cout << "  myList does not contain " << val << " index=" << myList.indexOf(val) << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "Remove some stuff:" << std::endl;
    std::string front = myList.removeFirst();
    std::string rear = myList.removeLast();
    std::cout << "Old front = " << front << std::endl;
    std::cout << "Old rear = " << rear << std::endl;
    std::cout << "Current list = " << myList.toString() << std::endl;
    std::cout << "Size = " << myList.size() << std::endl;
    std::cout << "First = " << myList.first() << std::endl;
    std::cout << "Last = " << myList.last() << std::endl;

    std::cout << std::endl;
    std::cout << "Contains testing (part 2):" << std::endl;
    for (int i = 0; i < searchCount; i++) {
        std::string val = searchValues[i];
        if (myList.contains(val)) {
            std::cout << "  myList contains " << val << " at index " << myList.indexOf(val) << std::endl;
        }
        else {
            std::cout << "  myList does not contain " << val << " index=" << myList.indexOf(val) << std::endl;
        }
    }

    std::cout << std::endl;
    std::cout << "Remove the rest of the nodes:" << std::endl;
    front = myList.removeFirst();
    rear = myList.removeLast();
    std::cout << "Old front = " << front << std::endl;
    std::cout << "Old rear = " << rear << std::endl;
    std::cout << "Current list = " << myList.toString() << std::endl;
    std::cout << "Size = " << myList.size() << std::endl;

    std::cout << std::endl;
    std::cout << "Finishing up:" << std::endl;
    myList.addToFront("The");
    myList.addToRear("End");
    std::cout << "First = " << myList.first() << std::endl;
    std::cout << "Last = " << myList.last() << std::endl;
    std::cout << "Current list = " << myList.toString() << std::endl;
    std::cout << "Size = " << myList.size() << std::endl;

    return 0;
}
