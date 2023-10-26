/*
 * File: TwoLetterWords.cpp
 * ------------------------
 * This program generates a list of the two-letter English words.
 */

#include <iostream>
#include "lexicon.h"
#include "console.h"
using namespace std;

int main() {
   Lexicon english("EnglishWords.txt");
   string word = "xx";
   for (char c0 = 'a'; c0 <= 'z'; c0++) {
      word[0] = c0;
      for (char c1 = 'a'; c1 <= 'z'; c1++) {
         word[1] = c1;
         if (english.contains(word)) {
            cout << word << endl;
         }
      }
   }
   return 0;
}
