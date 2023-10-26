/*
 * File: BeaconsOfGondor.cpp
 * -------------------------
 * This program illustrates the concept of a linked list by simulating the
 * Beacons of Gondor story from J. R. R. Tolkien's Return of the King.
 */

#include <fstream>
#include <iostream>
#include <string>
#include "console.h"
#include "error.h"
#include "stack.h"
using namespace std;

/*
 * Type: Tower
 * -----------
 * This structure contains the name of the tower and a link to the next one.
 */

struct Tower {
   string name;            /* The name of this tower                 */
   Tower *link;            /* Pointer to the next tower in the chain */
};

/* Function prototypes */

Tower *readBeaconsFromFile(string filename);
Tower *createTower(string name, Tower *link);
void signal(Tower *start);
void freeList(Tower *list);

/* Main program */

int main() {
   Tower *list = readBeaconsFromFile("BeaconsOfGondor.txt");
   signal(list);
   freeList(list);
   return 0;
}

/*
 * Function: readBeaconsFromFile
 * Usage: Tower *list = readBeaconsFromFile(filename);
 * ---------------------------------------------------
 * Creates a linked list of the towers whose names appear in the specified
 * file.  The names in the tower appear on individual lines, beginning at
 * the start of the chain.
 */

Tower *readBeaconsFromFile(string filename) {
   ifstream infile(filename.c_str());
   if (infile.fail()) error("Can't open input file" + filename);
   Stack<string> stack;
   string name;
   while (getline(infile, name)) {
      stack.push(name);
   }
   infile.close();
   Tower *tp = NULL;
   while (!stack.isEmpty()) {
      tp = createTower(stack.pop(), tp);
   }
   return tp;
}

/*
 * Function: createTower
 * Usage: Tower *chain = createTower(name, link);
 * ----------------------------------------------
 * Creates a new Tower structure with the specified components.
 */

Tower *createTower(string name, Tower *link) {
   Tower *tp = new Tower;
   tp->name = name;
   tp->link = link;
   return tp;
}

/*
 * Function: signal
 * Usage: signal(start);
 * ---------------------
 * Generates a signal starting at start and continuing through the
 * end of the chain.
 */

void signal(Tower *start) {
   if (start != NULL) {
      cout << "Lighting " << start->name << endl;
      signal(start->link);
   }
}

/*
 * Function: freeList
 * Usage: freeList(list);
 * ----------------------
 * Frees every cell in the linked list chain.  This method works
 * by using recursion to free the rest of the list before deleting
 * the current cell.
 */

void freeList(Tower *list) {
   if (list != NULL) {
      freeList(list->link);
      delete list;
   }
}
