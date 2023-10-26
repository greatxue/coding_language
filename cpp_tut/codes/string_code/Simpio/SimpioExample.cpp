/*
 * File: SimpioExample.cpp
 * -----------------------
 * This program is used to illustrate error-recovery in the simpio.h
 * library.
 */

#include <iostream>
#include "simpio.h"
using namespace std;

int main() {
   int n = getInteger("Enter an integer: ");
   cout << "You entered the integer " << n << endl;
   return 0;
}
