/**
 * @file point.cpp
 * Implementation of a point class.
 *
 * @author Lan Dao
 */

#include "point.h"

using namespace std;

/**
 * Construct a default point (0, 0).
 */
Point::Point() {
	x = 0;
	y = 0;
}

/**
 * Construct a point with given coordinates.
 */
Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}

/**
 * Operator ==.
 * Compare two points.
 */
bool Point::operator == (Point givenPoint) {
	if (x == givenPoint.x && y == givenPoint.y)
		return true;
	else
		return false;
}

/**
 * Check if the current point is in the middle of two given points.
 * If the three points are either not distinct or do not lie on the same
 * line, the behavior is undefined.
 */
bool Point::isInMiddle(Point firstPoint, Point secondPoint) {
	if (x < firstPoint.x && x > secondPoint.x) return true;
	if (x > firstPoint.x && x < secondPoint.x) return true;
	return false;
}

/**
 * Compute the distance between two points.
 */
double Point::distance(Point givenPoint) {
    return sqrt((x - givenPoint.x) * (x - givenPoint.x) + (y - givenPoint.y) * (y - givenPoint.y));
}

/**
 * Return the midpoint of a segment.
 */
Point Point::getMidpoint(Point givenPoint) {
    double midpoint_x = (x + givenPoint.x) / 2;
    double midpoint_y = (y + givenPoint.y) / 2;
    Point midpoint(midpoint_x, midpoint_y);
    return midpoint;
}
