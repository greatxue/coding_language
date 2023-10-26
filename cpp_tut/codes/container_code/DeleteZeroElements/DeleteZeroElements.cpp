/*
 * File: DeleteZeroElements.cpp
 * ----------------------------
 * This program tests the deleteZeroElements function.
 */

#include <iostream>
#include "vector.h"
#include "console.h"
using namespace std;

/* Function prototypes */

void removeZeroElements(Vector<int> & vec);
void addArrayToVector(Vector<int> & vec, int array[], int n);
void printVector(Vector<int> & vec);

/* Main program */

int main() {
   int array[] = { 0, 85, 90, 100, 0, 0, 92, 75, 0, 91, 63, 0 };
   Vector<int> vec;
   addArrayToVector(vec, array, 12);
   cout << "Before: ";
   printVector(vec);
   removeZeroElements(vec);
   cout << "After:  ";
   printVector(vec);
   return 0;
}

/*
 * Function: removeZeroElements
 * Usage: removeZeroElements(vec);
 * -------------------------------
 * This function goes through the elements of the vector and removes any
 * elements whose value is zero.  The loop operates in reverse order to
 * ensure that removing an element doesn't change the indices of the
 * elements that are left to be examined.
 */

void removeZeroElements(Vector<int> & vec) {
   for (int i = vec.size() - 1; i >= 0; i--) {
      if (vec[i] == 0) vec.remove(i);
   }
}

/*
 * Function: addArrayToVector
 * Usage: addArrayToVector(vec, array, n);
 * ---------------------------------------
 * This function adds the first n elements of array to the end of the vector.
 */

void addArrayToVector(Vector<int> & vec, int array[], int n) {
   for (int i = 0; i < n; i++) {
      vec.add(array[i]);
   }
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
