// ControlStructures.cpp
// C++ version of ControlStructures.java
//
// Java review topic: control structures. if/else, switch, while, do-while,
// for, break, and continue map almost 1-to-1 from Java to C++.
//
// Reading input: Java used a Scanner (scn.nextInt()). In C++ we read from
// std::cin with the >> operator.

#include <iostream>

int main() {
    // Control Structure examples
    int a = 5;
    int b, ii;

    std::cout << "Enter an integer : " << std::endl;
    std::cin >> b;   // C++ equivalent of Scanner's nextInt()

    // If-then-else statement (identical to Java)
    if (a < b) {
        std::cout << a << " is less than " << b << std::endl;
    }
    else {
        std::cout << a << " is not less than " << b << std::endl;
    }

    // Switch statement (identical to Java; break works the same way)
    switch (b) {
        case 1 :
            std::cout << "You entered a one." << std::endl;
            break;
        case 2 :
            std::cout << "You entered a two." << std::endl;
            break;
        case 3 :
            std::cout << "You entered a three." << std::endl;
            break;
        case 4 :
            std::cout << "You entered a four" << std::endl;
            break;
        default :  // The default case is used when no other cases match
            std::cout << "You entered a number greater than 4 or less than 1" << std::endl;
    }

    std::cout << "\nWhile loop : " << std::endl;
    ii = 0;
    while (ii <= b) {
        std::cout << "  Your number = " << b << ", loop variable = " << ii << std::endl;
        ii = ii + 2;
    }

    std::cout << "\nDo-while loop : " << std::endl;
    do {
        std::cout << "  Your number = " << b << ", loop variable = " << ii << std::endl;
        ii -= 2;
    } while ((ii > 0));

    std::cout << "\nFor loop : " << std::endl;
    for (ii = 0; ii < b; ii++) {
        std::cout << "  loop variable = " << ii << std::endl;
    }

    std::cout << "\nBreak example : " << std::endl;
    for (;;) {
        // Once a is bigger than 100 exit the loop
        if (a > 100) {
            std::cout << "  Breaking . . " << std::endl;
            break;
        }
        else {
            a++;
        }
    }

    std::cout << "\nContinue example : " << std::endl;
    for (ii = 0; ii <= b; ii++) {
        // If ii is not a multiple of 3 then go to next loop iteration
        if ((ii % 3) != 0) {
            continue;
        }
        std::cout << ii << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
