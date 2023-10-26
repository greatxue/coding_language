/*
 * File: VectorOperators.cpp
 * -------------------------
 * This program illustrates the + and += operators for the Vector class.
 */

#include <iostream>
#include "vector.h"
#include "console.h"
using namespace std;

/* Function prototypes */

void printVector(Vector<char> & vec);

/* Main program */

int main() {
   Vector<char> v1;
   Vector<char> v2;
   v1 += 'A', 'B', 'C';
   v2 += 'D', 'E';
   cout << "v1 = ";
   printVector(v1);
   cout << "v2 = ";
   printVector(v2);
   Vector<char> vec = v1 + v2;
   cout << "v1 + v2 = ";
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

void printVector(Vector<char> & vec) {
   cout << "[";
   for (int i = 0; i < vec.size(); i++) {
      if (i > 0) cout << ", ";
      cout << "'" << vec[i] << "'";
   }
   cout << "]" << endl;
}
