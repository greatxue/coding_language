/*
 * File: CharStackUnitTest.cpp
 * ---------------------------
 * This file contains a unit test of the CharStack class that uses the
 * C++ assert macro to check that each operation performs as it should.
 */

#include <iostream>
#include <cassert>
#include "charstack.h"
using namespace std;

int main() {
   CharStack cstk;                          /* Declare an empty CharStack  */
   assert(cstk.size() == 0);                /* Make sure its size is 0     */
   assert(cstk.isEmpty());                  /* And that isEmpty is true    */
   cstk.push('A');                          /* Push the character 'A'      */
   assert(!cstk.isEmpty());                 /* The stack is now not empty  */
   assert(cstk.size() == 1);                /* And has size 1              */
   assert(cstk.peek() == 'A');              /* Check that peek returns 'A' */
   cstk.push('B');                          /* Push the character 'B'      */
   assert(cstk.peek() == 'B');              /* Make sure peek returns it   */
   assert(cstk.size() == 2);                /* And that the size is now 2  */
   assert(cstk.pop() == 'B');               /* Pop and test for the 'B'    */
   assert(cstk.size() == 1);                /* Recheck the size            */
   assert(cstk.peek() == 'A');              /* And make sure 'A' is on top */
   cstk.push('C');                          /* Test a push after a pop     */
   assert(cstk.size() == 2);                /* Make sure size is correct   */
   assert(cstk.pop() == 'C');               /* And that pop returns a 'C'  */
   assert(cstk.peek() == 'A');              /* The 'A' is now back on top  */
   assert(cstk.pop() == 'A');               /* Pop and test for the 'A'    */
   assert(cstk.size() == 0);                /* And make sure size is 0     */
   for (char ch = 'A'; ch <= 'Z'; ch++) {   /* Push the entire alphabet    */
      cstk.push(ch);                        /*   one character at a time   */
   }                                        /*   to test stack expansion   */
   assert(cstk.size() == 26);               /* Make sure the size is 26    */
   for (char ch = 'Z'; ch >= 'A'; ch--) {   /* Pop the characters in       */
      assert(cstk.pop() == ch);             /*   reverse order to make     */
   }                                        /*   sure they're all there    */
   assert(cstk.isEmpty());                  /* Ensure the stack is empty   */
   for (char ch = 'A'; ch <= 'Z'; ch++) {   /* Push the alphabet again to  */
      cstk.push(ch);                        /*   test that it works after  */
   }                                        /*   expansion                 */
   assert(cstk.size() == 26);               /* Check that size is again 26 */
   cstk.clear();                            /* Check the clear method      */
   assert(cstk.size() == 0);                /* And check if stack is empty */
   cstk.clear();                            /* Test clear with empty stack */
   assert(cstk.size() == 0);
   cout << "CharStack unit test succeeded" << endl;
   return 0;
}
