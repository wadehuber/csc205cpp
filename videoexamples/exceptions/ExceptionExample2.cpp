#include <iostream>
#include <stdexcept>

// Example of exceptions, return, and "finally" across methods.
// In Java this was ExceptionExample2.
//
// Java's IllegalArgumentException becomes C++'s std::invalid_argument
// (both live in the standard library; std::invalid_argument is in <stdexcept>).

void checkNumber(int num) {
    std::cout << "\t\tSTART checkNumber " << num << std::endl;
    if (num < 0) {
        throw std::invalid_argument("");
    }
    std::cout << "\t\tEND checkNumber " << num << std::endl;
}

void doExample(int num) {
    std::cout << "\tSTART doExample " << num << std::endl;

    try {
        checkNumber(num);
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "\tEXCEPTION in doExample: illegal argument " << num << std::endl;
        // C++ has no "finally". In Java the finally block ran even though
        // this method returned here. To get the same behavior in C++, we
        // run that cleanup line before returning...
        std::cout << "\tFINALLY doExample " << num << std::endl;
        return;
    }

    // ...and also here, on the normal (no-exception) path, after the
    // try/catch. (RAII would be a cleaner way; see TryWithResourcesExample.)
    std::cout << "\tFINALLY doExample " << num << std::endl;

    std::cout << "\tEND doExample " << num << std::endl;
}

int main() {
    std::cout << "START" << std::endl;

    doExample(10);

    std::cout << std::endl;
    doExample(-10);

    std::cout << "END" << std::endl;

    return 0;
}
