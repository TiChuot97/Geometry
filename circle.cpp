/**
 * @file circle.cpp
 * Implementation of a circle class.
 *
 * @author Lan Dao
 */

#include "circle.h"

 using namespace std;

/**
 * Construct a circle with given center and coordinate.
 */
Circle::Circle(Point center, double radius) {
	this->center = center;
	this->radius = radius;
}

/**
 * Compute the area of the center.
 */
double Circle::area() {
	return PI * radius * radius;
}

/**
 * Compute the circumference of the circle.
 */
double Circle::circumference() {
    return 2 * radius * PI;
}


/**
 * Check whether a point lies in the circle.
 */
bool Circle::isInCircle(Point givenPoint) {
    
    // Compute the distance from the center to the given point
    double distance = center.distance(givenPoint);
    
    // If the distance is less than or equal the radius, 
    // the point lies in the circle.
    if (distance <= radius)
        return true;
    else
        return false;
}
