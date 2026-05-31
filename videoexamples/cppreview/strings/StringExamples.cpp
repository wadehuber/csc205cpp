// StringExamples.cpp
// C++ version of StringExamples.java -- driver for String205.
//
// Java review topic: string comparison. This is a KEY teaching point.
//
//   In JAVA:
//     - == on String compares REFERENCES (are they the same object?).
//       new String("Hello") makes a brand-new object, so myStr1 == myStr2 is
//       FALSE even though the text is identical.
//     - .equals() compares the actual characters (TRUE here).
//     - .compareTo() returns 0 when the characters match.
//
//   In C++:
//     - There is no "new String(...)" interning distinction. std::string ==
//       compares the CONTENTS (the characters), so myStr1 == myStr2 is TRUE.
//     - There is no .equals() method; == already does the value comparison.
//     - .compare() is the equivalent of Java's compareTo() (returns 0 if equal).
//
//   So the == comparison below prints a DIFFERENT result than Java: in Java
//   "myStr1 == myStr2" was false, but in C++ it is true. That difference is
//   the whole point of this example.

#include "String205.h"
#include <iostream>
#include <string>

int main() {
    std::string myStr1 = "Hello";
    // Java: new String("Hello") -> a distinct object. C++ has no equivalent;
    // this is just another std::string holding "Hello".
    std::string myStr2 = std::string("Hello");

    std::string str1 = "The sooner you get behind in your work, the more time you have to catch up.";
    std::string str2 = "The speed of a non-working program is irrelevant.";
    std::string str3 = "---> We have 5 example strings in CSC205! <---";

    std::cout << "Length of myStr1: " << myStr1.length() << std::endl;
    std::cout << "Length of myStr2: " << myStr2.length() << std::endl;
    std::cout << "Length of str1: " << str1.length() << std::endl;
    std::cout << "Length of str2: " << str2.length() << std::endl;
    std::cout << "Length of str3: " << str3.length() << std::endl;

    // String comparison
    std::cout << std::endl;
    std::cout << "Comparing strings with ==:" << std::endl;
    if (myStr1 == "Hello") {
        std::cout << "  " << myStr1 << " == " << myStr2 << std::endl;
    }
    else {
        std::cout << "  " << myStr1 << " != " << myStr2 << std::endl;
    }

    // In Java this branch printed "!=" (different objects). In C++ == compares
    // VALUE, so this prints "==".
    if (myStr1 == myStr2) {
        std::cout << "  " << myStr1 << " == " << myStr2 << std::endl;
    }
    else {
        std::cout << "  " << myStr1 << " != " << myStr2 << std::endl;
    }

    // Java used .equals(); in C++ == already does the value comparison.
    std::cout << "Comparing strings with equals():" << std::endl;
    if (myStr1 == myStr2) {
        std::cout << "  " << myStr1 << " == " << myStr2 << std::endl;
    }
    else {
        std::cout << "  " << myStr1 << " != " << myStr2 << std::endl;
    }

    // Java's compareTo() -> std::string::compare() (0 means equal).
    std::cout << "Comparing strings with compareTo():" << std::endl;
    if (myStr1.compare(myStr2) == 0) {
        std::cout << "  " << myStr1 << " == " << myStr2 << std::endl;
    }
    else {
        std::cout << "  " << myStr1 << " != " << myStr2 << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Original String 1: " << str1 << std::endl;
    std::cout << "   Letters only: " << justLetters(str1) << std::endl;
    std::cout << "   Vowels removed: " << noVowels(str1) << std::endl;
    std::cout << "   Individual words: ";
    individualWords(str1);
    std::cout << std::endl;

    std::cout << "Original String 2: " << str2 << std::endl;
    std::cout << "   Letters only: " << justLetters(str2) << std::endl;
    std::cout << "   Vowels removed: " << noVowels(str2) << std::endl;
    std::cout << "   Individual words: ";
    individualWords(str2);
    std::cout << std::endl;

    std::cout << "Original String 3: " << str3 << std::endl;
    std::cout << "   Letters only: " << justLetters(str3) << std::endl;
    std::cout << "   Vowels removed: " << noVowels(str3) << std::endl;
    std::cout << "   Individual words: ";
    individualWords(str3);
    std::cout << std::endl;

    return 0;
}
