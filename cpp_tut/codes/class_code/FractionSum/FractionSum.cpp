/*
 * File: FractionSum.cpp
 * ---------------------
 * This file illustrates the problem of roundoff error with
 * doubles.
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   float a = 1.0 / 2.0;
   float b = 1.0 / 3.0;
   float c = 1.0 / 6.0;
   float sum = a - b - c;
   cout << setprecision(16);
   cout << "1/2 - 1/3 - 1/6 = " << sum << endl;
   return 0;
}
