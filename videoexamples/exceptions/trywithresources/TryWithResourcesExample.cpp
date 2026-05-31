#include <iostream>
#include <stdexcept>
#include "OpenClose.h"

// Example showing the C++ equivalent of Java's try-with-resources.
// In Java this was TryWithResourcesExample.
//
// Java's try-with-resources automatically called close() on oc2 at the end
// of the try block. C++ has no such feature -- instead we use RAII and
// SCOPING: an OpenClose declared inside an inner { } block is destroyed (and
// thus "closed") at the end of that block. oc1, declared in main, lives
// until main ends, so Java had to close it by hand -- we mirror that here.
int main() {
    std::cout << "Starting" << std::endl;

    OpenClose oc1("OpenClose1");

    // This inner block plays the role of Java's try-with-resources: oc2 is
    // declared here and is automatically closed (its destructor runs) at the
    // closing brace -- whether we leave normally or via an exception.
    try {
        OpenClose oc2("OpenClose2");
        std::cout << "In try block" << std::endl;
        // oc2 is closed here automatically at the end of this scope.
    }
    // C++'s broad "catch (Exception e)" is "catch (const std::exception&)".
    catch (const std::exception& e) {
        std::cout << "In catch block" << std::endl;
    }
    // C++ has no "finally"; code after the try/catch always runs instead.
    std::cout << "In finallly block" << std::endl;

    // oc2 was closed automatically by scope; oc1 is still open, so we close
    // it by hand to match the Java (its destructor would otherwise close it
    // at the end of main -- our guard keeps it from closing twice).
    oc1.close();
    std::cout << "Ending" << std::endl;

    return 0;
}
