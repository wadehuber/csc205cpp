// RecursiveDefinition.cpp
//
// Walks through implementing a recursive function:
//   f(x) = 1                  if x <= 0
//   f(x) = 2x + f(x-1)        otherwise

#include <iostream>

int function(int x) {
    if (x <= 0) {
        return 1;
    }
    else {
        return (2 * x + function(x - 1));
    }
}

int main() {
    for (int ii = 0; ii <= 20; ii++) {
        std::cout << "f(" << ii << ") = " << function(ii) << std::endl;
    }
    return 0;
}
