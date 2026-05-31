// Static.cpp
// C++ version of Static.java (definitions).

#include "Static.h"
#include <string>

// DEFINITION of the static data members. This is REQUIRED in C++ -- the header
// only declares them. Each static member gets exactly one definition here.
int Static::staticVariable = 0;
int Static::counter = 0;
// (answer was initialized inline in the header because it is a const int.)

Static::Static(std::string name, int nonStaticVariable) {
    this->name = name;
    this->nonStaticVariable = nonStaticVariable;
    counter++;            // bump the shared counter
    this->myNum = counter;
}

// Static method: note there is no Static:: object here -- it only touches
// staticVariable (a static member). It does NOT use the 'static' keyword in
// the definition; that keyword only appears in the header declaration.
void Static::staticMethod(int x) {
    staticVariable += x;
}

void Static::nonStaticMethod(int x) {
    staticVariable += 1;          // can touch static members too
    nonStaticVariable += x;       // and this object's own copy
}

std::string Static::toString() const {
    return name + " [" + std::to_string(myNum) + " of " + std::to_string(counter) + "]" +
           ": [nonStaticVariable=" + std::to_string(nonStaticVariable) +
           ", staticVariable=" + std::to_string(staticVariable) +
           ", answer=" + std::to_string(answer) + "]";
}
