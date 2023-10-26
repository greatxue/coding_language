/*
 * File: PointTest.cpp
 * -------------------
 * This file creates and displays some points to test the
 * implementation of the Point class.
 */

#include <iostream>
#include "point.h"
using namespace std;

int main() {
   Point p0(0, 0);
   Point p1(3, 4);
   cout << boolalpha;
   cout << "p0 = " << p0 << endl;
   cout << "p1 = " << p1 << endl;
   cout << "(p0 == p0) = " << (p0 == p0) << endl;
   cout << "(p0 == p1) = " << (p0 == p1) << endl;
   cout << "(p0 != p0) = " << (p0 != p0) << endl;
   cout << "(p0 != p1) = " << (p0 != p1) << endl;
   cout << "The distance from " << p0
        << " to " << p1
        << " is " << dist(p0, p1) << endl;
   return 0;
}

