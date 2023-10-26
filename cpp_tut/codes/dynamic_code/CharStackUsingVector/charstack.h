/*
 * File: charstack.h
 * -----------------
 * This interface defines the CharStack class, which implements
 * the stack abstraction for characters.
 */

#ifndef _charstack_h
#define _charstack_h

#include "vector.h"

/*
 * Class: CharStack
 * ----------------
 * This class models a stack of characters.  The fundamental operations
 * are the same as those for the Stack<char> class.
 */

class CharStack {

public:

/*
 * Constructor: CharStack
 * Usage: CharStack cstk;
 * ----------------------
 * Initializes a new empty stack that can contain characters.
 */

   CharStack();

/*
 * Destructor: ~CharStack
 * Usage: (usually implicit)
 * -------------------------
 * Frees any heap storage associated with this character stack.
 */

   ~CharStack();

/*
 * Method: size
 * Usage: int nElems = cstk.size();
 * --------------------------------
 * Returns the number of characters in this stack.
 */

   int size();

/*
 * Method: isEmpty
 * Usage: if (cstk.isEmpty()) . . .
 * --------------------------------
 * Returns true if this stack contains no characters.
 */

   bool isEmpty();

/*
 * Method: clear
 * Usage: cstk.clear();
 * --------------------
 * Removes all characters from this stack.
 */

   void clear();

/*
 * Method: push
 * Usage: cstk.push(ch);
 * ---------------------
 * Pushes the character ch onto this stack.
 */

   void push(char ch);

/*
 * Method: pop
 * Usage: char ch = cstk.pop();
 * ----------------------------
 * Removes the top character from this stack and returns it.
 */

   char pop();

/*
 * Method: peek
 * Usage: char ch = cstk.peek();
 * -----------------------------
 * Returns the value of the top character from this stack without
 * removing it.  Raises an error if called on an empty stack.
 */

   char peek();

/* Private section */

/*
 * Implementation notes
 * --------------------
 * This version of the CharStack class uses a Vector<char> as its
 * underlying representation.  Characters are always added and
 * removed from the end, which gives rise to the last-in/first-out
 * behavior that is characteristic of stacks.
 */

private:

/* Instance variables */

   Vector<char> elements;    /* Data structure to hold the stack elements */

};

#endif
