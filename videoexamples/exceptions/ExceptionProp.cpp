#include <iostream>
#include <stdexcept>

// Example of exception propagation: function4 throws, but it is caught
// way back up in function2. In Java this was ExceptionProp.
//
// As in ExceptionExample, integer divide-by-zero does NOT throw in C++,
// so we throw an exception ourselves to demonstrate the same propagation.

void function4() {
    int val;

    std::cout << "      Function 4 start" << std::endl;

    std::cout << "      Create an exception" << std::endl;
    // Java did "val = 10 / 0;" which threw ArithmeticException ("/ by zero").
    // In C++ that would just crash (no exception), so we throw it ourselves.
    val = 0;
    throw std::runtime_error("/ by zero");
    std::cout << "val=" << val << std::endl;   // unreachable, kept to mirror Java

    std::cout << "      Function 4 end" << std::endl;
}

void function3() {
    std::cout << "    Function 3 start" << std::endl;
    function4();
    std::cout << "    Function 3 end" << std::endl;
}

void function2() {
    std::cout << "  Function 2 start" << std::endl;
    try {
        function3();
    }
    catch (const std::exception& excep) {
        std::cerr << std::endl;
        std::cout << "ERROR: An exception occurreed while running function3()" << std::endl;
        // Java used excep.getMessage(); in C++ the message is excep.what().
        std::cerr << "The exception message is: " << excep.what() << std::endl;
        std::cerr << std::endl;
        // Java printed a stack trace here. C++ has no built-in stack trace.
        std::cerr << "Call Stack Trace:" << std::endl;
        std::cerr << "(C++ has no built-in stack trace)" << std::endl;
        std::cerr << std::endl;
    }
    std::cout << "  Function 2 end" << std::endl;
}

void function1() {
    std::cout << "Function 1 start" << std::endl;
    function2();
    std::cout << "Function 1 end" << std::endl;
}

int main() {
    std::cout << "MAIN BEGIN" << std::endl;
    function1();
    std::cout << "MAIN END" << std::endl;
    return 0;
}
