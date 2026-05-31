#include "Point.h"

#include <string>

// Constructor
// NOTE: Just like the Java starter code, this body is intentionally empty
// and does NOT set x and y. (The members default to 0.0 from Point.h.)
Point::Point(double x, double y) {
}

// Swap x & y coordinates
void Point::swap() {
}

// Distance from A to origin (if we call A.distance())
double Point::distance() {
	return 0.0;
}

// Distance from A to B (if we call A.distance(B))
double Point::distance(Point b) {
	return 0.0;
}

// Shift along axis
void Point::shiftX(double s) {
}

void Point::shiftY(double s) {
}

// Rotate d radians
void Point::rotate(double d) {
}

// Returns the point in "(x, y)" form using the current x and y.
std::string Point::toString() const {
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}
