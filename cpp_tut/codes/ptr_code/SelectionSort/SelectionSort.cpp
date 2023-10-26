/*
 * File: SelectionSort.cpp
 * -----------------------
 * This file implements the selection sort algorithm using arrays
 * instead of vectors.
 */

#include <iostream>
using namespace std;

/* Function prototypes */

void sort(int array[], int n);
void swap(int & x, int & y);
void printArray(int array[], int n);

/* Main program */

int main() {
   int array[] = { 56, 25, 37, 58, 95, 19, 73, 30 };
   sort(array, 8);
   printArray(array, 8);
   return 0;
}

/*
 * Function: sort
 * Usage: sort(array, n);
 * ----------------------
 * Sorts the first n elements of array using the selection sort algorithm.
 */

void sort(int array[], int n) {
   for (int lh = 0; lh < n; lh++) {
      int rh = lh;
      for (int i = lh + 1; i < n; i++) {
         if (array[i] < array[rh]) rh = i;
      }
      swap(array[lh], array[rh]);
   }
}

/*
 * Function: swap
 * Usage: swap(x, y);
 * ------------------
 * Exchanges the values of x and y.  The arguments are passed by
 * reference and can therefore be modified.
 */

void swap(int & x, int & y) {
   int tmp = x;
   x = y;
   y = tmp;
}

/*
 * Function: printArray
 * Usage: printArray(array, n);
 * ----------------------------
 * Prints the first n elements of the array.
 */

void printArray(int array[], int n) {
   cout << "[";
   for (int i = 0; i < n; i++) {
      if (i > 0) cout << ", ";
      cout << array[i];
   }
   cout << "]" << endl;
}
