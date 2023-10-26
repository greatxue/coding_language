/*
 * File: symboltable.cpp
 * ---------------------
 * This file implements the SymbolTable class.
 */

#include <string>
#include "error.h"
#include "symboltable.h"
#include "vector.h"
using namespace std;

SymbolTable::SymbolTable() {
   /* Empty */
}

void SymbolTable::put(string key, double value) {
   int index = findKey(key);
   if (index == -1) {
      bindings.add(KeyValuePair());
      index = bindings.size() - 1;
      bindings[index].key = key;
   }
   bindings[index].value = value;
}

double SymbolTable::get(string key) {
   int index = findKey(key);
   if (index == -1) error("get: No binding for " + key);
   return bindings[index].value;
}

bool SymbolTable::containsKey(string key) {
   return findKey(key) != -1;
}

/*
 * Private method: findKey
 * Usage: int index = findKey(key);
 * --------------------------------
 * Returns the index in the bindings vector at which the key appears.
 * If key is not found, findKey returns -1.
 */

int SymbolTable::findKey(string key) {
   for (int i = 0; i < bindings.size(); i++) {
   	if (bindings[i].key == key) return i;
   }
   return -1;
}


      
