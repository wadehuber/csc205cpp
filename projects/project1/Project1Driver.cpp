#include <iostream>
#include <cmath>  // for M_PI

#include "Point.h"

int main() {
	Point p1(2, 4);
	Point p2(-1, 8);
	Point p3(0, 1);

	// In Java this was just ("Point 1: " + p1), which used the default
	// object toString. In C++ we call .toString() explicitly.
	std::cout << "Point 1: " << p1.toString() << std::endl;
	std::cout << "Point 2: " << p2.toString() << std::endl;
	std::cout << "Distance between " << p1.toString() << " and "
			<< p2.toString() << ": " << p1.distance(p2) << std::endl;
	p1.shiftX(3);
	p2.shiftY(-2);
	std::cout << "\nAfter shift:" << std::endl;
	std::cout << "Point 1: " << p1.toString() << std::endl;
	std::cout << "Point 2: " << p2.toString() << std::endl;
	std::cout << "Distance: " << p1.distance(p2) << std::endl;
	std::cout << "\nRotate test:" << std::endl;
	std::cout << "Before rotate: Point 3: " << p3.toString() << std::endl;
	p3.rotate(M_PI / 2);
	std::cout << " After rotate: Point 3: " << p3.toString() << std::endl;

	return 0;
}
