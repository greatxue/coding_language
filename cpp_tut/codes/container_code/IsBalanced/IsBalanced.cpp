/*
 * File: IsBalanced.cpp
 * --------------------
 * This program checks to see whether the standard bracketing operators
 * (parentheses, square brackets, and curly braces) are correctly matched.
 */

#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "stack.h"
using namespace std;

/* Function prototypes */

bool isBalanced(string exp);
bool operatorMatches(char open, char close);

/* Main program */

int main() {
   while (true) {
      string str = getLine("Enter string: ");
      if (str == "") break;
      if (isBalanced(str)) {
         cout << "Brackets are properly nested" << endl;
      } else {
         cout << "Brackets are incorrect" << endl;
      }
   }
   return 0;
}

/*
 * Function: isBalanced
 * Usage: if (isBalanced(str)) . . .
 * ---------------------------------
 * Returns true if the bracketing operators (parentheses, square
 * brackets, and curly braces) are correctly paired in the input string.
 */

bool isBalanced(string str) {
   Stack<char> stack;
   for (int i = 0; i < str.length(); i++) {
      char ch = str[i];
      switch (ch) {
        case '{': case '[': case '(': stack.push(ch); break;
        case '}': case ']': case ')':
          if (stack.isEmpty()) return false;
          if (!operatorMatches(stack.pop(), ch)) return false;
          break;
      }
   }
   return stack.isEmpty();
}

/*
 * Function: operatorMatches
 * Usage: if (operatorMatches(open, close)) . . .
 * ----------------------------------------------
 * Returns true if the characters open and close represent matching operators.
 * If op is not a bracketing operator, this function returns false.
 */

bool operatorMatches(char open, char close) {
   switch (open) {
     case '{': return close == '}';
     case '[': return close == ']';
     case '(': return close == ')';
     default: return false;
   }
}
