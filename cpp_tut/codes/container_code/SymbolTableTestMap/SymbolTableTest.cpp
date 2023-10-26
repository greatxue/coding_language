/*
 * File: SymbolTableTest.cpp
 * -------------------------
 * This file implements a simple test of the Map class by simulating
 * an assignment statements.
 *
 * The program reads command lines, which must be in one of
 * the following forms:
 *
 *   - A simple assignment statement of the form
 *        var = number
 *   - The name of a variable, which prints the value of that variable
 *   - The command list, which lists all variables and their values
 *   - The command quit, which should exit from the program.
 */

#include <iostream>
#include <string>
#include "console.h"
#include "map.h"
#include "simpio.h"
#include "strlib.h"
using namespace std;

/* Main program */

int main() {
   Map<string,double> symbolTable;
   while (true) {
      string line = getLine("> ");
      if (line == "quit") break;
      if (line == "list") {
         for (string key : symbolTable) {
            cout << key << " = " << symbolTable[key] << endl;
         }
      } else {
         int equals = line.find('=');
         if (equals == (int) string::npos) {
            string var = trim(line);
            if (symbolTable.containsKey(var)) {
               cout << symbolTable[var] << endl;
            } else {
               cout << var << " is undefined" << endl;
            }
         } else {
            string var = trim(line.substr(0, equals));
            double value = stringToReal(trim(line.substr(equals + 1)));
            symbolTable[var] = value;
         }
      }
   }
   return 0;
}
