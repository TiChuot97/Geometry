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
 * Operator ==.
 * Compare two circles.
 */
bool Circle::operator == (Circle givenCircle) {
    if (center == givenCircle.center && radius == givenCircle.radius)
        return true;
    else
        return false;
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

/**
 * Return the number of intersections between the circle
 * and a given line.
 */
int Circle::numberOfIntersectionLine(Line givenLine) {
    double distance = givenLine.distanceFromPoint(center);
    if (distance < radius) return 2;
    if (distance == radius) return 1;
    return 0;
}


/**
 * Return the number of intersections between two circles.
 */
int Circle::numberOfIntersectionCircle(Circle givenCircle) {
    double distance = center.distance(givenCircle.center);

    // The case where one circle contains the other
    if (distance < abs(radius - givenCircle.radius)) return 0;

    if (distance < radius + givenCircle.radius) return 2;
    if (distance == radius + givenCircle.radius) return 1;
    return 0;
}

/**
 * Return the pair of intersections between a line and a circle.
 * If the line intersects the circle at only one point, return
 * a pair of identical points.
 * If the line does not intersect the circle, the behavior is 
 * undefined.
 */
pair <Point, Point> Circle::getIntersectionLine(Line givenLine) {
    pair <Point, Point> default_return; // default variable to return in undefined cases

    // ax + b = y
    // (x - cx)^2 + (y - cy)^2 = r^2
    // (x - cx)^2 + (ax + b - cy)^2 = r^2
    // x^2 - 2xcx + cx^2 + (ax)^2 + 2a(b - cy)x + (b - cy)^2 - r^2 = 0
    // (a^2 + 1)x^2 + 2(ab - acy - cx)x + cx^2 + (b - cy)^2 - r^2 = 0
    double A = givenLine.a * givenLine.a + 1;
    double B = 2 * (givenLine.a * givenLine.b - givenLine.a * center.y - center.x);
    double C = (givenLine.b - center.y) * (givenLine.b - center.y) 
        - radius * radius + center.x * center.x;

    // Solve the equation: Ax^2 + Bx + C = 0
    double delta = B * B - 4 * A * C;

    if (delta < 0) return default_return;
    Point solution1, solution2;
    solution1.x = (-B + sqrt(delta)) / (2 * A);
    solution1.y = solution1.x * givenLine.a + givenLine.b;
    solution2.x = (-B - sqrt(delta)) / (2 * A);
    solution2.y = solution2.x * givenLine.a + givenLine.b;
    
    return pair <Point, Point> (solution1, solution2);
}
