/*
 * File: PrintVector.cpp
 * ---------------------
 * This program prints the elements of a vector.
 */

#include <iostream>
#include "vector.h"
#include "console.h"
using namespace std;

/* Function prototypes */

void printVector(Vector<int> & vec);

/* Main program */

int main() {
   Vector<int> vec;
   vec.add(10);
   vec.add(20);
   vec.add(30);
   vec.add(50);
   vec.insert(3, 40);
   vec.remove(0);
   vec.set(3, 70);
   printVector(vec);
   return 0;
}

/*
 * Function: printVector
 * Usage: printVector(vec);
 * ------------------------
 * This function prints the contents of the specified vector, followed by
 * the end-of-line character.  The elements are enclosed in square brackets
 * and separated by commas.
 */

void printVector(Vector<int> & vec) {
   cout << "[";
   for (int i = 0; i < vec.size(); i++) {
      if (i > 0) cout << ", ";
      cout << vec[i];
   }
   cout << "]" << endl;
}
