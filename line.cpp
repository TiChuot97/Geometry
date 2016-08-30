/**
 * @file line.cpp
 * Implementation of a line class.
 *
 * @author Lan Dao
 */

#include "line.h"

using namespace std;

/**
 * Construct a line with give slope and y_intercept.
 */
Line::Line(double a, double b) {
	this->a = a;
	this->b = b;
	vertical = false;
}

/**
 * Construct a line that goes through two given points.
 * If these given points are identical, this construct
 * a vertical line that goes through such point.
 */
Line::Line(Point firstPoint, Point secondPoint) {

	// If the x-coordinates of the two points are the same
	// it is either they are the same point or they lie on a vertical line.
	if (firstPoint.x == secondPoint.x) {
		a = 0;	// Set the slope to zero for easy implementation
		b = firstPoint.x;
		vertical = true;
	}
	// Otherwise compute the line normally
	else {
		a = (firstPoint.y - secondPoint.y) / (firstPoint.x - secondPoint.x);
		b = firstPoint.y - a * firstPoint.x;
		vertical = false;
	}
}

/**
 * Operator ==.
 * Compare two lines.
 */
bool Line::operator == (Line givenLine) {
    if (a == givenLine.a && b == givenLine.b && vertical == givenLine.isVertical())
        return true;
    else
        return false;
}

/**
 * Check if a line is vertical.
 */
bool Line::isVertical() {
	return vertical;
}

/**
 * Check if a give point lies on the current line.
 */
bool Line::isOnLine(Point givenPoint) {
	if (givenPoint.x * a + b == givenPoint.y)
		return true;
	else
		return false;
}

/**
 * Check if two lines are parallel.
 * Return true if two lines are identical.
 */
bool Line::isParallel(Line givenLine) {
	return (a == givenLine.a);
}


/**
 * Get the intersection of the current line and a given line.
 * If the two lines are parallel, the behavior is undefined.
 */
Point Line::getIntersection(Line givenLine) {
	double new_x = (givenLine.b - b) / (a - givenLine.a);
	double new_y = a * new_x + b;
	Point intersection(new_x, new_y);
	return intersection;
}


/**
 * Check if two given points lie on the same side of the current line.
 * Return true if any of the two points lie on the line.
 * If the two points are identical, the behavior is undefined.
 */
bool Line::isSameSide(Point firstPoint, Point secondPoint) {

	// If any of the two points lie on the line, return true
	if (isOnLine(firstPoint)) return true;
	if (isOnLine(secondPoint)) return true;

	// Create a line that goes through two given points
	Line d(firstPoint, secondPoint);

	// If d and the current line are parallel, given points lie on same side
	if (isParallel(d)) return true;

	// Get the intersection of d and the current line
	Point intersection = getIntersection(d);

    // Check if the intersection is in the middle of two given points
    if (intersection.isInMiddle(firstPoint, secondPoint))
        return false;
    else
        return true;
}


/**
 * Compute the distance from a given point to the line.
 */
double Line::distanceFromPoint(Point givenPoint) {

    // Create a line go through the point and perpendicular to the line
    Line perpendicularLine(-(1 / a), givenPoint.y + givenPoint.x / a);

    // Find the intersection of two lines
    Point intersection = getIntersection(perpendicularLine);

    // The distance between the intersection and the given point
    // is also the distance between the line and the given point
    return intersection.distance(givenPoint);
}


/**
 * Compute the distance between two lines.
 */
double Line::distanceBetweenLines(Line givenLine) {
    
    // Pick a random point on one line and compute the
    // distance from that point to the other line
    Point randomPoint(0, givenLine.b);
    return distanceFromPoint(randomPoint);
}
