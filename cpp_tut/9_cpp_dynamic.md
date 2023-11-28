# 9. Dynamic Memory Management

*Last Update: 23-10-18*

## 9.1 Dynamic Allocation

### 9.1.1 Basic Memory Allocation

Here are two basic C++ syntaxes of memory allocation, and always pair these two when using:

+ The `new` operator to allocate memory on the heap

  ```cpp
  int * pi = new int; 			// allocate space for a int on the heap
  int * arr = new int[10];  // allocate an array of 10 integers
  ```
  
+ The `delete` operator frees memory previously allocated.

  ```cpp
  delete pi;
  delete [] arr; // for arrays
  ```
  As you see, no *size* is needed to be specified for `delete []`. 
  
  Also, `delete ptr` only frees the memory space pointed by `ptr`, but not the memory space occupied by itself. `ptr` is still a live, **dangling** variable until it is released.
  
  To avoid dangling pointers, after deleting a pointer one can *nullify* a pointer by
  
  ```cpp
  ptr = NULL; // nullptr since C++11
  ```

Here is an example of ***dynamic arrays***:

```cpp
int *createIndexArray(int n) {
   int *array = new int[n];
   for (int i = 0; i < n; i++) {
      array[i] = i;
   }
   return array;
}

int main() {
   int *digits = createIndexArray(10);
   delete [] digits;
}
```

**Garbage collection**

The biggest challenge in working with dynamic memory allocation is to free the heap memory you allocate, or it will cause ***memory leaks***.

Garbage collection frees the programmer from manually dealing with *memory deallocation*, but is not always efficient in performances as manual allocations. In C++, objects can be allocated **either on the stack or in the heap**, and programmers must manage heap memory allocation **explicitly**.

### 9.1.2 Destructor

In C++, class definitions often include a ***destructor***, which specifies how to free the storage used to represent an instance of that class.

The prototype for a destructor **has no return type** and uses the name of the class preceded by a tilde `~`. The destructor must not take any arguments.

C++ calls the destructor automatically whenever a variable of a particular class is released. For stack objects, this happens **when the function returns**, so as to automatically reclaim those variables of the object previously declared as local variables on the *stack*.

If you instead allocate space for an object in the *heap* using `new`, you must explicitly free that object by calling `delete`, which automatically invokes the destructor. Also, if `new` is used in constructors, `delete` should most probably be used in destructors as well.

**Heap-Stack Diagram**

Here we will use a **heap-stack diagram**, where a block of memory to the **heap** side of the diagram will be added when using `new`, and a new **stack** frame will be created whenever a program calls a *method* (with its memory reclaimed when a method returns).

![9-1](pictures/9-1.png)

**Dynamic Allocation in C**

Supported in `<cstdlib>` (for the header file`stdlib.h`):

| Function  | Description                        |
| --------- | ---------------------------------- |
| `calloc`  | Allocate and zero-initialize array |
| `free`    | Deallocate memory block            |
| `malloc`  | Allocate memory block              |
| `realloc` | Reallocate memory block            |

## 9.2 Linked Structures

Pointers are important in programming because they make it possible to represent the relationship among objects by **linking them together** in various ways.

![9-3](pictures/9-3.png)

C++ marks the end of linked list using the constant `NULL`, which signifies a pointer that does not have an actual target.

Here is a vivid example of passing the message via the towers:

```cpp
   string name;  /* The name of this tower    */
   Tower *link;  /* Pointer to the next tower */
};

/*
 * Function: createTower(name, link);
 * ----------------------------------
 * Creates a new Tower with the specified values.
 */

Tower *createTower(string name, Tower *link) {
   Tower *tp = new Tower;
   tp->name = name;
   tp->link = link;
   return tp;
}

/*
 * Function: signal(start);
 * ------------------------
 * Generates a signal beginning at start.
 */
 
void signal(Tower *start) {
   if (start != NULL) {
      cout << "Lighting " << start->name << endl;
      signal(start->link);
   }
}
```

For a better understanding, we implement a `CharStack` Class using dynamic allocation. The comments are intentionally removed for readers' further thoughts.

+ Here we have the `charstack.h` interface:

  ```cpp
  /*
   * File: charstack.h
   * -----------------
   * This interface defines the CharStack class.
   */
  
  #ifndef _charstack_h
  #define _charstack_h
  
  class CharStack {
  public:
  
  /*
   * CharStack constructor and destructor
   * ------------------------------------
   * The constructor initializes an empty stack.  The destructor
   * is responsible for freeing heap storage.
   */
  
     CharStack();
     ~CharStack();
    
  /*
   * Methods: size, isEmpty, clear, push, pop
   * ----------------------------------------
   * These methods work exactly as they do for the Stack class.
   * The peek method is deleted here to save space.
   */
  
     int size();
     bool isEmpty();
     void clear();
     void push(char ch);
     char pop();
  
  #include "charstackpriv.h"
  
  }
  
  #endif
  ```

+ Here is what in the even deeper `charstackpriv.h` file:

  ```cpp
  /*
   * File: charstackpriv.h
   * ---------------------
   * This file contains the private data for the CharStack class.
   */
  
  private:
  
  /* Instance variables */
  
     char *array;          /* Dynamic array of characters   */
     int capacity;         /* Allocated size of that array  */
     int count;            /* Current count of chars pushed */
  
  /* Private function prototypes */
  
     void expandCapacity();
  ```

+ Thus we implement the `charstack.cpp` file:

  ```cpp
  /*
   * File: charstack.cpp
   * -------------------
   * This file implements the CharStack class.
   */
  
  #include "charstack.h"
  #include "error.h"
  using namespace std;
  
  /*
   * Constant: INITIAL_CAPACITY
   * --------------------------
   * This constant defines the initial allocated size of the dynamic
   * array used to hold the elements.  If the stack grows beyond its
   * capacity, the implementation doubles the allocated size.
   */
  
  const int INITIAL_CAPACITY = 10;
  
  /*
   * Implementation notes: constructor and destructor
   * ------------------------------------------------
   * The constructor allocates dynamic array storage to hold the
   * stack elements.  The destructor must free these elements
   */
  
  CharStack::CharStack() {
     capacity = INITIAL_CAPACITY;
     array = new char[capacity];
     count = 0;
  }
  
  CharStack::~CharStack() {
     delete[] array;
  }
  
  int CharStack::size() {
     return count;
  }
  
  bool CharStack::isEmpty() {
     return count == 0;
  }
  
  void CharStack::clear() {
     count = 0;
  }
  
  void CharStack::push(char ch) {
     if (count == capacity) expandCapacity();
     array[count++] = ch;
  }
  
  char CharStack::pop() {
     if (isEmpty()) error("pop: Attempting to pop an empty stack");
     return array[--count];
  }
  
  /*
   * Implementation notes: expandCapacity
   * ------------------------------------
   * This private method doubles the capacity of the elements array
   * whenever it runs out of space.  To do so, it must copy the
   * pointer to the old array, allocate a new array with twice the
   * capacity, copy the characters from the old array to the new
   * one, and finally free the old storage.
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
  ```

From the codes above, there are two which deserves paying attention to:

+ **`array` and `oldArray`:** 

  In the code, `array` is the **original** character array pointer, and `oldArray` is a **backup** pointer used to save the original address of `array`. When you reallocate memory for `array` (using `new`), `array` will point to the new memory address, while `oldArray` still points to the original memory address.

+ **Here `++i` and `i++` are quite different:** 

  `array[count++] = ch;` first **stores** the value `ch` at the current position in `array` (specified by the `count` index) and then *increments* `count` by 1.

  `return array[--count];` first *decrements* `count` by 1 and then **returns** the value of `array` at that position.

## 9.3 Copying Objects

When you are defining a new *ADT* in C++, you typically need to define two methods to ensure that copies are handled correctly:

+ The operator `operator=`, which takes care of **assignments**;

  ```cpp
  type & type::operator=(const type & src)
  ```

+ A *copy constructor*, which takes care of **by-value parameters**.

  ```cpp
  type::type(const type & src)
  ```

Call/return by value might cause unnecessary calls to the copy constructor. **Constant call by reference** protects the source.

**Assignment and Copy Constructors**

An assignment operator can return anything it wants, but the standard C/C++ *assignment operators* return a *reference* to the left-hand operand, which allows you to **chain** assignments together:

```cpp
int a, b, c;
a = b = c = 10;
```

The default behavior of C++ is to **copy** only the top-level fields in an object, which means that all dynamically allocated memory is shared between the original and the copy, known as ***shallow copying***:

+ A ***shallow copy*** allocates new fields for the object itself and copies the information from the original. Unfortunately, the dynamic array is copied as an address, not the data.
+ A ***deep copy*** also copies the contents of the dynamic array and therefore creates two independent structures

Here we implement a ***deep copy***. These methods make it possible to pass a `CharStack` by value or assign one `CharStack` to another.
```cpp
/*
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * These methods make it possible to pass a CharStack by value or
 * assign one CharStack to another.
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

void CharStack::deepCopy(const CharStack & src) {
   array = new char[src.count];
   for (int i = 0; i < src.capacity; i++) {
      array[i] = src.array[i];
   }
   count = src.count;
   capacity = src.capacity;
}

```

## 9.4 Unit Testing

One of the most important responsibilities you have as a programmer is to test your code as thoroughly as you can. Thus we adpat **unit test** of the `assert` macro from the `<cassert>` library on the implementation of a stack:

![9-4](pictures/9-4.png)

## 9.5 `const` and `static`

### 9.5.1 The Uses of `const`

The `const` keyword has many distinct purposes in C++. This text uses it in the following three contexts:

+ **Constant definitions**. Adding the keyword `const` to a variable definition tells the compiler to disallow subsequent assignments to that variable, thereby making it constant.

  ```cpp
  const double PI = 3.14159265358979323846;
  static const int INITIAL_CAPACITY = 10;
  ```
+ **Constant call by reference**. Adding `const` to the declaration of a reference parameter signifies that the function will not change the value of that parameter. 

  ```cpp
  void deepCopy(const CharStack & src);
  ```
+ **Constant methods**. Adding `const` after the parameter list of a method guarantees that the method will not change the object.

  ```cpp
  int CharStack::size() const
  ```

Classes that use the `const` specification for all appropriate parameters and methods are said to be `const`-correct. 

As an example,

```cpp
#include <iostream>
using namespace std;

class A {
public:
   const int c1;
   const int c2;
   A();
   A(int x, int y);
};

A::A():c1(3),c2(4){}
A::A(int x, int y):c1(x),c2(y){}

int main() {
   A a;
   A b(5, 6);
   cout << a.c1 << a.c2 << endl; // 34
   cout << b.c1 << b.c2 << endl; // 56
}
```

also

```cpp
#include <iostream>
using namespace std;

class A {
public:
   const int c1 = 1; // Since C++11
   const int c2 = 2; // Since C++11
};

int main() {
   A a, b;
   cout << a.c1 << a.c2 << endl; 			// 12
   cout << b.c1 << b.c2 << endl;			// 12
   cout << (&a.c1 == &b.c1) << endl;	// 0
   cout << (&a.c2 == &b.c2) << endl;	// 0
}
```

### 9.5.2 The Uses of `static`

The lifetime of `static` variables **begins** the first time the program flow **encounters the declaration** and it **ends** at program **termination**:

| Applied to                           | Meaning                                                      |
| ------------------------------------ | ------------------------------------------------------------ |
| a local variable                     | The variable is permanent, in the sense that it is **initialized only once** and retains its value from one function call to the next. It is like having a *global variable* (life span), but only with local scope (effective scope). |
| a global constant                    | Since a global constant has **internal linkage** by default, meaning it is only available for use in the file in which it is defined thus in effect, `static const`. |
| a global variable or a free function | The scope is limited to the file in which it is defined with a `static` qualifier, or any free function or global variable in a file has the extern qualifier by default. |
| a member variable                    | There is **only one** such variable for the class, no matter how many objects of the class are created, turning the member variable from an *instance variable* into a *class variable*. |
| a member function                    | The function may access **only static members** of the class, not any *instance members*. |

```cpp
#include <iostream>
using namespace std;

class A {
public:
   static const int c = 1;
   static int i;
};

int A::i = 2;

int main() {
   A a, b;
   cout << a.c << a.i << endl;			// 12
   cout << b.c << b.i << endl;			// 12
   cout << (&a.c == &b.c) << endl;	// 1
   cout << (&a.i == &b.i) << endl;	// 1
   a.i = 3;
   cout << b.i << endl;							// 3
}
```

---

