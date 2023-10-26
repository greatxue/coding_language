/*
 * File: SwapIntegers.cpp
 * ----------------------
 * This program illustrates the use of call by reference to exchange
 * the values of two integers.
 */

#include <iostream>
using namespace std;

/* Function prototype */

void swap(int *px, int *py);

/* Main program */

int main() {
   int n1, n2;
   cout << "Enter n1: ";
   cin >> n1;
   cout << "Enter n2: ";
   cin >> n2;
   if (n1 > n2) swap(&n1, &n2);
   cout << "The range is " << n1 << " to " << n2 << "." << endl;
   return 0;
}

/*
 * Function: swap
 * Usage: swap(px, py);
 * --------------------
 * Exchanges the integer values pointer to by px and py.
 */

void swap(int *px, int *py) {
   int tmp = *px;
   *px = *py;
   *py = tmp;
}
