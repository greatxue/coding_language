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
 * through the end of the chain.
 */

void signal(Tower *start) {
   for (Tower *tp = start; tp != NULL; tp = tp->link) {
      cout << "Lighting " << tp->name << endl;
   }
}

/*
 * Function: freeList
 * Usage: freeList(list);
 * ----------------------
 * Frees every cell in the linked list chain.
 */

void freeList(Tower *list) {
   while (list != NULL) {
      Tower *next = list->link;
      delete list;
      list = next;
   }
}
