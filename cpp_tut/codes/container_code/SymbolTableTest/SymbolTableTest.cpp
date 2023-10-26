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
 *   - The command quit, which should exit from the program.
 */

#include <iostream>
#include <string>
#include "console.h"
#include "simpio.h"
#include "strlib.h"
#include "symboltable.h"
using namespace std;

/* Main program */

int main() {
   SymbolTable symtab;
   while (true) {
      string line = getLine("> ");
      if (line == "quit") break;
      int equals = line.find('=');
      if (equals == string::npos) {
         string var = trim(line);
         if (symtab.containsKey(var)) {
            cout << symtab.get(var) << endl;
         } else {
            cout << "No binding for " << var << endl;
         }
      } else {
         string var = trim(line.substr(0, equals));
         double value = stringToReal(trim(line.substr(equals + 1)));
         symtab.put(var, value);
      }
   }
   return 0;
}
