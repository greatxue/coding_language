/*
 * File: FindAnagrams.cpp
 * ----------------------
 * This program finds all anagrams of a given set of letters.
 */

#include <iostream>
#include <string>
#include "console.h"
#include "lexicon.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

/* Function prototypes */

void displayAnagrams(string tiles, Lexicon & english);
string sortLetters(string str);

/* Main program */

int main() {
   Lexicon english("EnglishWords.txt");
   while (true) {
      cout << "Enter tiles: ";
      string tiles = getLine();
      if (tiles == "") break;
      displayAnagrams(toLowerCase(tiles), english);
   }
   return 0;
}

/*
 * Function: displayAnagrams
 * Usage: displayAnagrams(tiles, english);
 * ---------------------------------------
 * Prints out a list of all the anagrams of the characters in the string
 * tiles that are listed in the lexicon as English words.
 */

void displayAnagrams(string tiles, Lexicon & english) {
   string match = sortLetters(tiles);
   for (string word : english) {
      if (match == sortLetters(word)) {
         cout << word << endl;
      }
   }
}

/*
 * Function: sortLetters
 * Usage: string sorted = sortLetters(str);
 * ----------------------------------------
 * Returns a string that contains the same letters as the argument string str
 * but in which those characters appear in sorted order.  Thus, calling
 * sortLetters("cabbage") returns "aabbceg".  Implementation note: Because
 * str is passed by value, changing its contents does not affect the value
 * of the parameter in the caller.
 */

string sortLetters(string str) {
   int n = str.length();
   for (int lh = 0; lh < n - 1; lh++) {
      int rh = lh;
      for (int i = lh + 1; i < n; i++) {
         if (str[i] < str[rh]) rh = i;
      }
      char tmp = str[lh];
      str[lh] = str[rh];
      str[rh] = tmp;
   }
   return str;
}
