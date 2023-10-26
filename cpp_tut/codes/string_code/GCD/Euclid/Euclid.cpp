/*
 * File: Euclid.cpp
 * ----------------
 * This program calculates the greatest common divisor of two numbers
 * by applying Euclid's algorithm.
 */

#include <iostream>
#include <ctime>
//#include "console.h"
#include "gcd.h"
using namespace std;

/* Main program */

int main() {
   int x, y, z;
   time_t begin, end;
   double diff;
   cout << "Program to compute the greatest common divisor." << endl;
   cout << "Enter x: ";
   cin >> x;
   cout << "Enter y: ";
   cin >> y;
   time(&begin);
   z = gcd(x, y);
   diff = difftime(time(&end), begin);
   cout << "The gcd is " << z << ", calculated in " << diff << " seconds." << endl;
   return 0;
}
