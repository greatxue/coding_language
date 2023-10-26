/*
 * File: charstack.cpp
 * -------------------
 * This file implements the CharStack class using a Vector<char> as the
 * underlying representation.  The Vector class already implements most
 * of the essential operations for the CharStack class, which can simply
 * forward the request to the underlying structure.  The methods are
 * short enough to require no detailed documentation.
 */

#include "charstack.h"
#include "error.h"
#include "vector.h"
using namespace std;

CharStack::CharStack() {
   /* Empty */
}

CharStack::~CharStack() {
   /* Empty */
}

int CharStack::size() {
   return elements.size();
}

bool CharStack::isEmpty() {
   return elements.isEmpty();
}

void CharStack::clear() {
   elements.clear();
}

void CharStack::push(char ch) {
   elements.add(ch);
}

char CharStack::pop() {
   if (isEmpty()) error("pop: Attempting to pop an empty stack");
   char result = elements[elements.size() - 1];
   elements.remove(elements.size() - 1);
   return result;
}

char CharStack::peek() {
   if (isEmpty()) error("peek: Attempting to peek at an empty stack");
   return elements[elements.size() - 1];
}
