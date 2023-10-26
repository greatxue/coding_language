/*
 * File: tokenscanner.cpp
 * ----------------------
 * This file implements the TokenScanner class.  Most of the methods
 * are straightforward enough to require no additional documentation.
 */

#include <cctype>
#include <string>
#include "tokenscanner.h"
using namespace std;

TokenScanner::TokenScanner() {
   /* Empty */
}

TokenScanner::TokenScanner(string str) {
   setInput(str);
}

void TokenScanner::setInput(string str) {
   buffer = str;
   cp = 0;
}

bool TokenScanner::hasMoreTokens() {
   if (ignoreWhitespaceFlag) skipWhitespace();
   return cp < buffer.length();
}

/*
 * Implementation notes: nextToken
 * -------------------------------
 * This method starts by looking at the current character, which is
 * indicated by the index cp.  If the index is past the end of the string,
 * nextToken returns the empty string.  If the character is alphanumeric,
 * nextToken scans ahead until it finds the end of a word; if not,
 * nextToken returns the character as a one-character string.
 */

string TokenScanner::nextToken() {
   if (ignoreWhitespaceFlag) skipWhitespace();
   if (cp >= buffer.length()) {
      return "";
   } else if (isalnum(buffer[cp])) {
      int start = cp;
      while (cp < buffer.length() && isalnum(buffer[cp])) {
         cp++;
      }
      return buffer.substr(start, cp - start);
   } else {
      return string(1, buffer[cp++]);
   }
}

/*
 * Implementation notes: ignoreWhitespace and skipWhitespace
 * ---------------------------------------------------------
 * The ignoreWhitespace method simply sets a flag.  The private method
 * skipWhitespace is called only if that flag is true.
 */

void TokenScanner::ignoreWhitespace() {
   ignoreWhitespaceFlag = true;
}

void TokenScanner::skipWhitespace() {
   while (cp < buffer.length() && isspace(buffer[cp])) {
      cp++;
   }
}
