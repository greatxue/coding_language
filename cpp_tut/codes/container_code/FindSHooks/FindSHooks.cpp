/*
 * File: FindSHooks.cpp
 * --------------------
 * This program finds all the English words that have S hooks on
 * both ends.
 */

#include <iostream>
#include "console.h"
#include "lexicon.h"
//#include "foreach.h"
using namespace std;

int main() {
   Lexicon english("EnglishWords.txt");
//   foreach (string word in english) {
   for (string word : english) {
      if (english.contains("s" + word) && english.contains(word + "s")) {
         cout << word << endl;
      }
   }
   return 0;
}
