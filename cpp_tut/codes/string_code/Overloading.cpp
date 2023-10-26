#include <iostream>
#include "console.h"
using namespace std;

/* Function prototypes */

//int printinput(int x = 0);
//int printinput(int x = 1, int y = 2);
int printinput(int x = 0) { return x; }
int printinput(int x = 1, int y = 2) { return y; }

/* Main program */

int main() {
   int x, y;
   cout << "Enter x: ";
   cin >> x;
   cout << "Enter y: ";
   cin >> y;
   cout << printinput() << endl;
   return 0;
}

//int printinput(int x) { return x; }
//int printinput(int x, int y) { return y; }
