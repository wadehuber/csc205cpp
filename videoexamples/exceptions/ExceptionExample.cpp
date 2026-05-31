#include <iostream>
#include <stdexcept>

// Example of using exceptions in C++.
// In Java this was ExceptionExample with a main() method.
//
// NOTE on "divide by zero": in Java, "3 / 0" with ints throws an
// ArithmeticException. In C++, integer divide-by-zero is "undefined
// behavior" -- it does NOT throw, and usually just crashes. So to show
// the same idea (catch an exception), we THROW one ourselves on purpose.
int main() {
    int num = 10;
    int beforeNum = 20;
    int afterNum = 30;
    int finallyNum = 40;
    int zero = 0;

    std::cout << "Before try block:" << std::endl;
    std::cout << "  num = " << num << std::endl;
    std::cout << "  beforeNum = " << beforeNum << std::endl;
    std::cout << "  afterNum = " << afterNum << std::endl;
    std::cout << "  finallyNum = " << finallyNum << std::endl;
    std::cout << std::endl;

    try {
        beforeNum = -20;
        // Java did "num = 3 / zero;" which threw ArithmeticException.
        // C++ would just crash, so we check and throw to mimic Java.
        if (zero == 0) {
            throw std::runtime_error("/ by zero");
        }
        num = 3 / zero;
        afterNum = -30;
    }
    catch (const std::exception& excep) {
        // Java printed a stack trace; C++ has no built-in stack trace,
        // so we print the exception message instead (e.what()).
        std::cerr << "Exception: " << excep.what() << std::endl;
        std::cerr << "Hey, you can't divide by zero!" << std::endl;
    }
    // C++ has NO "finally". The cleanup that Java put in a finally block
    // simply goes AFTER the try/catch here -- it always runs.
    std::cout << "Finally, done with this." << std::endl;
    finallyNum = -40;

    std::cout << std::endl;
    std::cout << "After try block:" << std::endl;
    std::cout << "  num = " << num << std::endl;
    std::cout << "  beforeNum = " << beforeNum << std::endl;
    std::cout << "  afterNum = " << afterNum << std::endl;
    std::cout << "  finallyNum = " << finallyNum << std::endl;

    return 0;
}
