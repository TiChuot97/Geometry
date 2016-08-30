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
#include "point.h"

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
};

#endif
