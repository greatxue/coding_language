/*
 * File: SetBasedLexicon.cpp
 * -------------------------
 * This program creates a lexicon using a Set<string>.  The main
 * program simply prints out the list of two-letter words.
 */

#include <iostream>
#include <fstream>
#include "set.h"
#include "console.h"
//#include "foreach.h"
using namespace std;

void initLexicon(Set<string> & english);

int main() {
   Set<string> lexicon;
   initLexicon(lexicon);
//   foreach (string word in lexicon) {
   for (string word : lexicon) {
      if (word.length() == 2) {
         cout << word << endl;
      }
   }
   return 0;
}

void initLexicon(Set<string> & lexicon) {
   ifstream infile;
   infile.open("EnglishWords.txt");
   if (infile.fail()) error("Can't open EnglishWords.txt");
   string word;
   while (getline(infile, word)) {
      lexicon.add(word);
   }
   infile.close();
}
