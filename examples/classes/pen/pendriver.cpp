#include "fourcolorpen.hpp"
#include <iostream>

int main() {
    FourColorPen myPen;
    FourColorPen pen2;
    
    std::cout << "After instantiating:" << std::endl;
    std::cout << "  myPen: " << myPen.toString() << std::endl;
    std::cout << "  pen2: " << pen2.toString() << std::endl;
    std::cout << std::endl;
    
    // Initial color is NONE, so nothing should write
    myPen.write("You shouldn't see this");
    pen2.write("You shouldn't see this, either!");
    
    myPen.click("blue");
    myPen.write("Hello, world!");
    
    pen2.click("GrEeN");
    pen2.write("The end!");
    myPen.click("RED");
    myPen.write("Goodbye!");
    
    std::cout << std::endl;
    std::cout << "End of main:" << std::endl;
    std::cout << "  myPen: " << myPen.toString() << std::endl;
    std::cout << "  pen2: " << pen2.toString() << std::endl;
    
    return 0;
}