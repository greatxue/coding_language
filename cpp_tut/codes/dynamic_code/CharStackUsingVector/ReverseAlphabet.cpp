/*
 * File: ReverseAlphabet.cpp
 * -------------------------
 * This program reverses the letters in the alphabet by pushing each
 * character onto a CharStack.
 */

#include <iostream>
#include <string>
#include "charstack.h"
using namespace std;

int main() {
   CharStack cstk;
   for (int i = 0; i < 26; i++) {
      cstk.push(char('A' + i));
   }
   while (!cstk.isEmpty()) {
      cout << cstk.pop();
   }
   cout << endl;
   return 0;
}
