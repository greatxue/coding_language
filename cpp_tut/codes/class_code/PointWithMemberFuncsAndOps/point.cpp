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

bool Point::operator==(Point p2) {
   return x == p2.x && y == p2.y;
}

bool Point::operator!=(Point p2) {
   return x != p2.x || y != p2.y;
}

double Point::dist(Point p2) {
   double dx = x - p2.getX();
   double dy = y - p2.getY();
   return sqrt(dx * dx + dy * dy);
}

ostream & operator<<(ostream & os, Point pt) {
   return os << pt.toString();
}
