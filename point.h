/**
 * @file point.h
 * Definitions for functions for point class
 *
 * @author Lan Dao
 */

#ifndef _POINT_H_
#define _POINT_H_

#include <cmath>
#include <cstdlib>

class Point {
	public:
		double x;	// The x-coordinate of the point
		double y; 	// The y-coordinate of the point

		/**
		 * Construct a default point (0, 0).
		 */
		Point();

		/**
		 * Construct a point with given coordinates.
		 */
		Point(double x, double y);

		/**
		 * Operator ==.
		 * Compare two points.
		 */
		bool operator == (Point givenPoint);

		/**
		 * Check if the current point is in the middle of two given points.
		 * If the three points are either not distinct or do not lie on the same
		 * line, the behavior is undefined.
		 */
		bool isInMiddle(Point firstPoint, Point secondPoint);

        /**
         * Compute the distance between two points.
         */
        double distance(Point givenPoint);

        /**
         * Return the midpoint of a segment.
         */
        Point getMidpoint(Point givenPoint);
};

#endif 
