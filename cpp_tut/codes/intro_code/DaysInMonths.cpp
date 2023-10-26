/*
 * File: DaysInMonths.cpp
 * -------------------------
 * This program shows the number of days in a specific month.
 */

#include <iostream>
using namespace std;

int main() {
   int month;
   cout << "Enter numeric month (Jan=1): ";
   cin >> month;
   switch (month) {
     case 2:
       cout << "28 days (29 in leap years)" << endl;
       break;
     case 4: case 6: case 9: case 11:
       cout << "30 days" << endl;
       break;
     case 1: case 3: case 5: case 7: case 8: case 12:
       cout << "31 days" << endl;
       break;
     default:
       cout << "Illegal month number" << endl;
       break;
   }
   return 0;
}
