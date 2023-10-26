/*
 * File: TwoLetterWords.cpp
 * ------------------------
 * This program generates a list of the two-letter words.
 */

#include <iostream>
#include "lexicon.h"
#include "console.h"
//#include "foreach.h"
using namespace std;

int main() {
   Lexicon english("EnglishWords.txt");
//   foreach (string word in english) {
   for (string word : english) {
      if (word.length() == 2) {
         cout << word << endl;
      }
   }
   return 0;
}
