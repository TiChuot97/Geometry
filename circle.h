/**
 * @file circle.h
 * Definitions for functions for circle class
 *
 * @author Lan Dao
 */

#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include <cmath>
#include <cstdlib>
#include <utility>
#include "point.h"
#include "line.h"

const double PI = 3.14159265;

class Circle {
    public:
        Point center;   // The center of the circle
        double radius;  // The radius of the circle

        /**
         * Construct a circle with given center and coordinate.
         */
      	Circle(Point center, double radius);

		/**
		 * Operator ==.
		 * Compare two circles.
		 */
        bool operator == (Circle givenCircle); 

      	/**
      	 * Compute the area of the circle.
      	 */
      	double area();

      	/**
      	 * Compute the circumference of the circle.
      	 */
      	double circumference();

        /**
         * Check whether a point lies in the circle.
         */
        bool isInCircle(Point givenPoint);

        /**
         * Return the number of intersections between the circle
         * and a given line.
         */
        int numberOfIntersectionLine(Line givenLine);

        /**
         * Return the number of intersections between two circles.
         */
        int numberOfIntersectionCircle(Circle givenCircle);

        /**
         * Return the pair of intersections between a line and a circle.
         * If the line intersects the circle at only one point, return
         * a pair of identical points.
         * If the line does not intersect the circle, the behavior is 
         * undefined.
         */
        std::pair <Point, Point> getIntersectionLine(Line givenline);
};

#endif
