/*
 * File: point.cpp
 * ---------------
 * This file implements the point.h interface.  The comments have been
 * eliminated from this listing so that the implementation fits on a
 * single page.
 */

#include <string>
#include <math.h>
#include "point.h"
using namespace std;

Point::Point() {
   x = 0;
   y = 0;
}

Point::Point(int xc, int yc) {
   x = xc;
   y = yc;
}

int Point::getX() {
   return x;
}

int Point::getY() {
   return y;
}

string Point::toString() {
   return "(" + to_string(x) + "," + to_string(y) + ")";
}

ostream & operator<<(ostream & os, Point pt) {
   return os << pt.toString();
}

bool operator==(Point p1, Point p2) {
   return p1.getX() == p2.getX() && p1.getY() == p2.getY();
}

bool operator!=(Point p1, Point p2) {
   return !(p1 == p2);
}

double dist(Point p1, Point p2) {
   double dx = p2.getX() - p1.getX();
   double dy = p2.getY() - p1.getY();
   return sqrt(dx * dx + dy * dy);
}
