/*
 * File: RationalTest.cpp
 * ----------------------
 * Simple test of the Rational class.
 */

#include <iostream>
#include "rational.h"
#include "console.h"
using namespace std;

int main() {
   Rational a(1, 2);
   Rational b(1, 3);
   Rational c(1, 6);
   Rational sum = add(add(a, b), c);
   cout << a << " + " << b << " + " << c << " = " << sum << endl;
   return 0;
}
