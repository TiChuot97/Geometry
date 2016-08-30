/**
 * @file line.h
 * Definitions for functions for line class
 *
 * @author Lan Dao
 */

#ifndef _LINE_H_
#define _LINE_H_

#include "point.h"
#include <cmath>
#include <cstdlib>

class Line {
	public:
		double a;	// The slope of the line
		double b;	// The y_intercept of the line

		/**
		 * Construct a line with give slope and y_intercept.
		 */
		Line(double a, double b);

		/**
		 * Construct a line that goes through two given points.
		 * If these given points are identical, this construct
		 * a vertical line that goes through such point.
		 */
		Line(Point firstPoint, Point secondPoint);

        /**
         * Operator ==.
         * Compare two lines.
         */
        bool operator == (Line givenLine);
        

		/**
		 * Check if a line is vertical.
		 */
		bool isVertical();

		/**
		 * Check if a give point lies on the current line.
		 */
		bool isOnLine(Point givenPoint);

		/**
		 * Check if two lines are parallel.
		 * Return true if two lines are identical.
		 */
		bool isParallel(Line givenLine);

        /**
         * Get the intersection of the current line and a given line.
         * If the two lines are parallel, the behavior is undefined.
         */
        Point getIntersection(Line givenLine);

		/**
		 * Check if two given points lie on the same side of the current line.
		 * Return true if any of the two points lie on the line.
		 * If the two points are identical, the behavior is undefined.
		 */
		bool isSameSide(Point firstPoint, Point secondPoint);

        /**
         * Compute the distance from a given point to the line.
         */
        double distanceFromPoint(Point givenPoint);

        /**
         * Compute the distance between two lines.
         */
        double distanceBetweenLines(Line givenLine);

	private:
		bool vertical;
};

#endif
