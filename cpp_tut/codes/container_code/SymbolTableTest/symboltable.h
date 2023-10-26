/*
 * File: symboltable.h
 * -------------------
 * This file exports the SymbolTable class.
 */

#ifndef _symboltable_h
#define _symboltable_h

#include <string>
#include "vector.h"

/*
 * Class: SymbolTable
 * ------------------
 * The SymbolTable class implements an association between strings and
 * floating-point values without using a Map.
 */

class SymbolTable {

public:

/*
 * Constructor: SymbolTable
 * Usage: SymbolTable symtab;
 * --------------------------
 * Initializes a SymbolTable that is initially empty.
 */

   SymbolTable();

/*
 * Method: put
 * Usage: symtab.put(key, value);
 * ------------------------------
 * Sets key to value in the symbol table.
 */

   void put(std::string key, double value);

/*
 * Method: get
 * Usage: double value = symtab.get(key);
 * --------------------------------------
 * Returns the value associated with key in the symbol table.
 * If key is not found, the get method signals an error.
 */

   double get(std::string key);

/*
 * Method: containsKey
 * Usage: if (symtab.containsKey(key)) . . .
 * -----------------------------------------
 * Returns true if the symbol table contains the specified key.
 */

   bool containsKey(std::string key);

/* Private section */

private:

/*
 * Type: KeyValuePair
 * ------------------
 * This type represents a key-value pair in the map.
 */

   struct KeyValuePair {
      std::string key;
      double value;
   };

/* Instance variables */

   Vector<KeyValuePair> bindings;

/* Private methods */

   int findKey(std::string key);

};

#endif
