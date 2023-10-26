/*
 * File: CStyleStrings.cpp
 * -----------------------
 * This program tests several of the functions used with C-style
 * strings.
 */

#include <iostream>
#include <iomanip>
//#include "console.h"

using namespace std;

int main() {

    int **ppi, *pi, i = 10; pi = &i; ppi = &pi;
    cout << "int **ppi, *pi, i = 10; pi = &i; ppi = &pi;" << endl << endl;
    cout << "&i: " << &i << endl;
    cout << "i: " << i << endl;
    cout << "&pi: " << &pi << endl;
    cout << "pi: " << pi << endl;
    cout << "*pi: " << *pi << endl;
    cout << "&ppi: " << &ppi << endl;
    cout << "ppi: " << ppi << endl;
    cout << "*ppi: " << *ppi << endl;
    cout << "**ppi: " << **ppi << endl << endl;

    double doubleArray[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    double* doublePointer = doubleArray;
    cout << "double doubleArray[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};" << endl;
    cout << "double* doublePointer = doubleArray;" << endl << endl;
    cout << "doubleArray: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(doubleArray) << endl;
    cout << "&doubleArray[0]: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(&doubleArray[0]) << endl;
    cout << "*doubleArray: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(*doubleArray) << endl;
    cout << "doubleArray[0]: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(doubleArray[0]) << endl;
    cout << "doubleArray+1: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(doubleArray+1) << endl;
    cout << "&doubleArray[1]: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(&doubleArray[1]) << endl;
    cout << "*doubleArray+1: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(*doubleArray+1) << endl;
    cout << "*(doubleArray+1): " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(*(doubleArray+1)) << endl;
    cout << "doubleArray[1]: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(doubleArray[1]) << endl;
    cout << "doubleArray+9: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(doubleArray+9) << endl;
    cout << "&doubleArray[9]: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(&doubleArray[9]) << endl;
    cout << "*(doubleArray+9): " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(*(doubleArray+9)) << endl;
    cout << "doubleArray[9]: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(doubleArray[9]) << endl;
    cout << "doubleArray+10: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(doubleArray+10) << endl;
    cout << "&doubleArray[10]: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(&doubleArray[10]) << endl;
    cout << "*(doubleArray+10): " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(*(doubleArray+10)) << endl;
    cout << "doubleArray[10]: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(doubleArray[10]) << endl;
    cout << "doubleArray-1: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(doubleArray-1) << endl;
    cout << "*doubleArray-1: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(*doubleArray-1) << endl;
    cout << "*(doubleArray-1): " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(*(doubleArray-1)) << endl;
    cout << "&doubleArray: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(&doubleArray) << endl;
    cout << "&doubleArray+1: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(&doubleArray+1) << endl;
    cout << "*(&doubleArray+1): " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(*(&doubleArray+1)) << endl;
    cout << "&doubleArray-1: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(&doubleArray-1) << endl;
    cout << "*(&doubleArray-1): " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(*(&doubleArray-1)) << endl << endl;

    cout << "doublePointer: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(doublePointer) << endl;
    cout << "doublePointer+1: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(doublePointer+1) << endl;
    cout << "&doublePointer: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(&doublePointer) << endl;
    cout << "&doublePointer+1: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(&doublePointer+1) << endl;
    cout << "doublePointer[0]: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(doublePointer[0]) << endl;
    cout << "doublePointer[1]: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(doublePointer[1]) << endl;
    cout << "doublePointer[9]: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(doublePointer[9]) << endl;
    cout << "doublePointer[10]: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(doublePointer[10]) << endl;
    cout << "&doublePointer[0]: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(&doublePointer[0]) << endl;
    cout << "&doublePointer[1]: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(&doublePointer[1]) << endl;
    cout << "&doublePointer[9]: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(&doublePointer[9]) << endl;
    cout << "&doublePointer[10]: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(&doublePointer[10]) << endl;
    cout << "*doublePointer: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(*doublePointer) << endl;
    cout << "*doublePointer+1: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(*doublePointer+1) << endl;
    cout << "*(doublePointer+1): " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(*(doublePointer+1)) << endl;
    cout << "*doublePointer++: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(*doublePointer++) << endl;
    cout << "*++doublePointer: " << hex << setfill('0') << uppercase;
    cout << setw(8) << long(*++doublePointer) << endl << endl;

   char charArray[] = "acegikmoqs";
   char* charPointer = "acegikmoqs";
   cout << "char charArray[] = \"acegikmoqs\";" << endl;
   cout << "char* charPointer = \"acegikmoqs\";" << endl << endl;
   cout << "charArray: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(charArray) << endl;
   cout << "charArray+1: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(charArray+1) << endl;
   cout << "&charArray: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(&charArray) << endl;
   cout << "&charArray+1: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(&charArray+1) << endl;
   cout << "charArray[0]: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(charArray[0]) << endl;
   cout << "charArray[1]: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(charArray[1]) << endl;
   cout << "charArray[9]: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(charArray[9]) << endl;
   cout << "charArray[10]: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(charArray[10]) << endl;
   cout << "&charArray[0]: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(&charArray[0]) << endl;
   cout << "&charArray[1]: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(&charArray[1]) << endl;
   cout << "&charArray[9]: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(&charArray[9]) << endl;
   cout << "&charArray[10]: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(&charArray[10]) << endl;
   cout << "*charArray: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(*charArray) << endl;
   cout << "*charArray+1: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(*charArray+1) << endl;
   cout << "*(charArray+1): " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(*(charArray+1)) << endl << endl;

   cout << "charPointer: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(charPointer) << endl;
   cout << "charPointer+1: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(charPointer+1) << endl;
   cout << "&charPointer: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(&charPointer) << endl;
   cout << "&charPointer+1: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(&charPointer+1) << endl;
   cout << "charPointer[0]: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(charPointer[0]) << endl;
   cout << "charPointer[1]: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(charPointer[1]) << endl;
   cout << "charPointer[9]: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(charPointer[9]) << endl;
   cout << "charPointer[10]: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(charPointer[10]) << endl;
   cout << "&charPointer[0]: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(&charPointer[0]) << endl;
   cout << "&charPointer[1]: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(&charPointer[1]) << endl;
   cout << "&charPointer[9]: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(&charPointer[9]) << endl;
   cout << "&charPointer[10]: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(&charPointer[10]) << endl;
   cout << "*charPointer: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(*charPointer) << endl;
   cout << "*charPointer+1: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(*charPointer+1) << endl;
   cout << "*(charPointer+1): " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(*(charPointer+1)) << endl;
   cout << "*charPointer++: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(*charPointer++) << endl;
   cout << "*++charPointer: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(*++charPointer) << endl << endl;

   cout << "charPointer: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(charPointer) << endl;
   cout << "charPointer+1: " << hex << setfill('0') << uppercase;
   cout << setw(8) << long(charPointer+1) << endl;
   cout << "doubleArray[10]: " << hex << setfill('0') << uppercase;
   cout << setw(8) << doubleArray[10] << endl;

   return 0;
}
