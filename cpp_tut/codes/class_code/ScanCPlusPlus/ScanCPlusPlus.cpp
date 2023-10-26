/*
 * File: ScanCPlusPlus.cpp
 * -----------------------
 * This program uses the token scanner to read C++ code.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "filelib.h"
#include "tokenscanner.h"
#include "console.h"
using namespace std;

/* Function prototypes */

void scanCPlusPlusTokens(TokenScanner & scanner);

/* Main program */

int main() {
   ifstream infile;
   promptUserForFile(infile, "C++ source file: ");
   TokenScanner scanner;
   scanCPlusPlusTokens(scanner);
   scanner.setInput(infile);
   while (scanner.hasMoreTokens()) {
      cout << scanner.nextToken() << endl;
   }
   infile.close();
   return 0;
}

/*
 * Function: scanCPlusPlusTokens
 * Usage: scanCPlusPlusTokens(scanner);
 * ------------------------------------
 * Sets the necessary options for the scanner so that it can
 * read C++ source code.
 */

void scanCPlusPlusTokens(TokenScanner & scanner) {
   scanner.ignoreWhitespace();
   scanner.ignoreComments();
   scanner.scanNumbers();
   scanner.scanStrings();
   scanner.addWordCharacters("_");
   scanner.addOperator("++");
   scanner.addOperator("--");
   scanner.addOperator("==");
   scanner.addOperator("!=");
   scanner.addOperator("<=");
   scanner.addOperator(">=");
   scanner.addOperator("<<");
   scanner.addOperator(">>");
   scanner.addOperator("&&");
   scanner.addOperator("||");
   scanner.addOperator("+=");
   scanner.addOperator("-=");
   scanner.addOperator("*=");
   scanner.addOperator("%=");
   scanner.addOperator("^=");
   scanner.addOperator("&=");
   scanner.addOperator("|=");
   scanner.addOperator("<<=");
   scanner.addOperator(">>=");
   scanner.addOperator("->");
   scanner.addOperator("::");
}
