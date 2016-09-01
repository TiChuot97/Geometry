/**
 * @file triangle.h
 * Definitions for functions for triangle class
 *
 * @author Lan Dao
 */

#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include "point.h"
#include <cmath>
#include <cstdlib>

class Triangle {
    public:
        Point A;    // Vertex A
        Point B;    // Vertex B
        Point C;    // Vertex C

        /**
         * Construct a new triangle.
         */
        Triangle(Point A, Point B, Point C);

        /**
         * Compute the area of the triangle.
         */
        double area();

        /**
         * Compute the circumference of the triangle.
         */
        double circumference();

        /**
         * Check if a triangle is right.
         */
        bool isRight();

        /**
         * Check if a triangle is equilateral.
         */
        bool isEquilateral();

        /**
         * Check if a point lies in a triangle.
         */
        bool isInTriangle(Point givenPoint);

    private:
        double a;       // The length of the opposite edge to vertex A
        double b;       // The length of the opposite edge to vertex B
        double c;       // The length of the opposite edge to vertex C
        double heightA; // The height of the triangle according to a
        double heightB; // The height of the triangle according to b
        double heigntC; // The height of the triangle according to c
};

#endif
