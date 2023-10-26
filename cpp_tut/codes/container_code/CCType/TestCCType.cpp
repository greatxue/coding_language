/*
 * File: TestCCType.cpp
 * --------------------
 * This program tests the set-based implementation of the <cctype>
 * interface.
 */

#include <iostream>
#include <string>
#include "cctype.h"
#include "simpio.h"
#include "console.h"
using namespace std;

int main() {
   while (true) {
      string str = getLine("Enter one or more characters: ");
      if (str == "") break;
      cout << boolalpha;
      for (int i = 0; i < str.length(); i++) {
         char ch = str[i];
         cout << " isdigit('" << ch << "') -> " << isdigit(ch) << endl;
         cout << " isxdigit('" << ch << "') -> " << isxdigit(ch) << endl;
         cout << " islower('" << ch << "') -> " << islower(ch) << endl;
         cout << " isupper('" << ch << "') -> " << isupper(ch) << endl;
         cout << " isspace('" << ch << "') -> " << isspace(ch) << endl;
         cout << " ispunct('" << ch << "') -> " << ispunct(ch) << endl;
         cout << " isalpha('" << ch << "') -> " << isalpha(ch) << endl;
         cout << " isalnum('" << ch << "') -> " << isalnum(ch) << endl;
         cout << " isprint('" << ch << "') -> " << isprint(ch) << endl;
         cout << endl;
      }
   }
   return 0;
}
