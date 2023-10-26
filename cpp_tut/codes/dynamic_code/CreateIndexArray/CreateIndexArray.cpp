/*
 * File: CreateIndexArray.cpp
 * --------------------------
 * This file tests the createIndexArray function.
 */

#include <iostream>
using namespace std;

/* Function prototypes */

int *createIndexArray(int n);
void printArray(int array[], int n);

/* Test program */

int main() {
   for (int i = 0; i < 10; i++) {
      int *array = createIndexArray(i);
      cout << "createIndexArray(" << i << ") -> ";
      printArray(array, i);
      delete[] array;
   }
   return 0;
}

/*
 * Function: createIndexArray
 * Usage: int *array = createIndexArray(n);
 * ----------------------------------------
 * Returns a new dynamic integer array of length n in which every
 * element is set to its own index.
 */

int* createIndexArray(int n) {
   int* array = new int[n];
   for (int i = 0; i < n; i++) {
      array[i] = i;
   }
   return array;
}

/*
 * Function: printArray
 * Usage: printArray(array, n);
 * ----------------------------
 * Prints on cout the elements of the array, which has n as its
 * effective size.
 */

void printArray(int array[], int n) {
   cout << "[";
   for (int i = 0; i < n; i++) {
      if (i > 0) cout << ", ";
      cout << array[i];
   }
   cout << "]" << endl;
}
