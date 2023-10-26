/*
 * File: charstack.cpp
 * -------------------
 * This file implements the CharStack class.
 */

#include "charstack.h"
#include "error.h"
using namespace std;

/*
 * Implementation notes: constructor and destructor
 * ------------------------------------------------
 * The constructor allocates the array storage for the stack elements and
 * initializes the fields of the object.  The destructor frees any heap
 * memory allocated by the class, which is just the array of elements.
 */

CharStack::CharStack() {
   capacity = INITIAL_CAPACITY;
   array = new char[capacity];
   count = 0;
}

CharStack::~CharStack() {
   delete[] array;
}

/*
 * Implementation notes: size, isEmpty, clear
 * ------------------------------------------
 * These methods are each a single line and need no detailed documentation.
 * Note that size and isEmpty leave the stack unchanged and are therefore
 * marked as const.
 */

int CharStack::size() const {
   return count;
}

bool CharStack::isEmpty() const {
   return count == 0;
}

void CharStack::clear() {
   count = 0;
}

/*
 * Implementation notes: push
 * --------------------------
 * This function first checks to see whether there is enough room for
 * the character and then expands the array storage if necessary.
 */

void CharStack::push(char ch) {
   if (count == capacity) expandCapacity();
   array[count++] = ch;
}

/*
 * Implementation notes: pop, peek
 * -------------------------------
 * These functions check for an empty stack and report an error if
 * there is no top element.
 */

char CharStack::pop() {
   if (isEmpty()) error("pop: Attempting to pop an empty stack");
   return array[--count];
}

char CharStack::peek() const {
   if (isEmpty()) error("peek: Attempting to peek at an empty stack");
   return array[count - 1];
}

/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * These methods make it possible to pass a CharStack by value or
 * assign one CharStack to another.  The actual work is done by the
 * private deepCopy method, which represents a useful pattern
 * for designing other classes that need to implement deep copying.
 */

CharStack::CharStack(const CharStack & src) {
   deepCopy(src);
}

CharStack & CharStack::operator=(const CharStack & src) {
   if (this != &src) {
      delete[] array;
      deepCopy(src);
   }
   return *this;
}

/*
 * Implementation notes: deepCopy
 * ------------------------------
 * This method copies the data from the src parameter into the current
 * object.  All dynamic memory is reallocated to create a "deep copy"
 * in which the current object and the source object are independent.
 */

void CharStack::deepCopy(const CharStack & src) {
   array = new char[src.count];
   for (int i = 0; i < src.count; i++) {
      array[i] = src.array[i];
   }
   count = src.count;
   capacity = src.capacity;
}

/*
 * Implementation notes: expandCapacity
 * ------------------------------------
 * This method doubles the capacity of the elements array whenever it runs
 * out of space.  To do so, the method must copy the pointer to the old
 * array, allocate a new array with twice the capacity, copy the characters
 * from the old array to the new one, and finally free the old storage.
 */

void CharStack::expandCapacity() {
   char *oldArray = array;
   capacity *= 2;
   array = new char[capacity];
   for (int i = 0; i < count; i++) {
      array[i] = oldArray[i];
   }
   delete[] oldArray;
}
