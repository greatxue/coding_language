/*
 * File: BeaconsOfGondor.cpp
 * -------------------------
 * This program illustrates the concept of a linked list by simulating the
 * Beacons of Gondor story from J. R. R. Tolkien's Return of the King.
 */

#include <iostream>
#include <string>
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

Tower *createBeaconsOfGondor();
Tower *createTower(string name, Tower *link);
void signal(Tower *start);
void freeList(Tower *list);

/* Main program */

int main() {
   Tower *list = createBeaconsOfGondor();
   signal(list);
   freeList(list);
   return 0;
}

/*
 * Function: createBeaconsOfGondor
 * Usage: Tower *list = createBeaconsOfGondor();
 * ---------------------------------------------
 * Creates a linked list of the towers described by Tolkien.  The function
 * builds the list backwards and returns a pointer to the first tower.
 */

Tower *createBeaconsOfGondor() {
   Tower *tp = createTower("Rohan", NULL);
   tp = createTower("Halifirien", tp);
   tp = createTower("Calenhad", tp);
   tp = createTower("Min-Rimmon", tp);
   tp = createTower("Erelas", tp);
   tp = createTower("Nardol", tp);
   tp = createTower("Eilenach", tp);
   tp = createTower("Amon Din", tp);
   return createTower("Minas Tirith", tp);
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
 * Generates a signal starting at the current tower and proceeding
 * through the end of the chain.  This version of signal operates
 * recursively, printing out the name of the current tower and then
 * calling itself recursively on the rest of the list.
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
