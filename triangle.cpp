/**
 * @file triangle.cpp
 * Implementation of a triangle class.
 *
 * @author Lan Dao
 */

#include "triangle.h"

using namespace std;

/**
 * Construct a new triangle.
 */
Triangle::Triangle(Point A, Point B, Point C) {
    this->A = A;
    this->B = B;
    this->C = C;
    a = B.distance(C);
    b = C.distance(A);
    c = A.distance(B);
    
    // Construct the lines go through AB, AC, BC
    Line lineAB(A, B);
    Line lineBC(B, C);
    Line lineCA(C, A);

    heightA = lineBC.distanceFromPoint(A);
    heightB = lineCA.distanceFromPoint(B);
    heightC = lineAB.distanceFromPoint(C);
}

/**
 * Compute the area of the triangle.
 */
double Triangle::area() {
    return (heightA * a) / 2;
}

/**
 * Compute the circumference of the triangle.
 */
double Triangle::circumference() {
    return a + b + c;
}

/**
 * Check if a triangle is right.
 */
bool Triangle::isRight() {
    if (a * a == b * b + c * c) return true;
    if (b * b == c * c + a * a) return true;
    if (c * c == a * a + b * b) return true;
    return false;
}

/**
 * Check if a triangle is equilateral.
 */
bool Triangle::isEquilateral() {
    if (a == b && b == c)
        return true;
    else
        return false;
}

/**
 * Check if a point lies in a triangle.
 */
bool Triangle::isInTriangle(Point givenPoint) {
    
    // If a point lies outside the triangle, one of the following should be true:
    //  - Given point and A lies on different side of BC.
    //  - Given point and B lies on different side of CA.
    //  - Given point and C lies on different side of AB.

    // Construct the lines go through AB, AC, BC
    Line lineAB(A, B);
    Line lineBC(B, C);
    Line lineCA(C, A);

    if (!lineAB.isSameSide(givenPoint, C)) return false;
    if (!lineBC.isSameSide(givenPoint, A)) return false;
    if (!lineCA.isSameSide(givenPoint, B)) return false;
}
