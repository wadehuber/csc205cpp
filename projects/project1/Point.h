#ifndef POINT_H
#define POINT_H

#include <string>

class Point {
private:
	// In Java these were just "double x, y;". In C++ uninitialized
	// members hold garbage (undefined behavior), so we give them
	// default values of 0.0 to stay safe. The constructor body is
	// still empty, just like the Java starter code.
	double x = 0.0, y = 0.0;

public:
	// Constructor
	Point(double x, double y);

	// Swap x & y coordinates
	void swap();

	// Distance from A to origin (if we call A.distance())
	double distance();

	// Distance from A to B (if we call A.distance(B))
	double distance(Point b);

	// Shift along axis
	void shiftX(double s);

	void shiftY(double s);

	// Rotate d radians
	void rotate(double d);

	// In Java, printing a Point used Object's default toString (an object
	// hash). C++ has no automatic object printing, so we add a simple
	// toString so the driver can print something readable. You will flesh
	// out the real behavior of this class as part of the project.
	std::string toString() const;
};

#endif
