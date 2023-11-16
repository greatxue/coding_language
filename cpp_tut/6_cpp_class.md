# 6. OOP I: Classes

## 6.1 Data Types in C++

There are numerous data types provided in C++:

+ **Primitive types:** basic data types including but not limited to `int`, `double`, `bool` (`true` or `false`) and `char` (representing a single ASCII character).
+ **Collections**
+ **Compound data types:** more complex data types like *Enumerated types*, *Structures* and *Classes*.

### 6.1.1 Enumerated types

An enumerated type can be roughly considered as a subset of `int` with special names.

+ It could be automatically assigned by numbers from 0:

  ```cpp
  enum Direction { NORTH, EAST, SOUTH, WEST }; 
  ```

+ It could be assigned manually as well:

  ```cpp
  enum Coin {
    PENNY = 1,
    NICKEL = 5,
    DIME = 10
  };
  ```

### 6.1.2 Structures

There are compound values in which the individual components are specified by name, called ***structures***. It creates a *type*, not a *variable*.

```cpp
struct Point {
  int x;
  int y;
};
```

This definition allows to declare a `Point` variable like:

```cpp
Point pt;
```

Given the variable `pt`, you can select the individual *fields* or *members* using the dot operator `.` as in `pt.x` and `pt.y`.

## 6.2 Classes

### 6.2.1 Construction of a Class
**The Format of a Class**
In C, structures define the **representation** of a compound value, while functions define **operations** on these data. 

In C++, these two ideas are integrated. Most data structures are represented as ***objects*** based on the idea of a *class*. The class definition specifies the representation of the object by naming its *fields* or *instance variables*, and the behavior of the object by providing a set of *methods*.

New objects are created as ***instances*** of a particular class, and the creation of new instances is called ***instantiation***.

For example, you could represent points using a Class like:

```cpp
class Point {
    public:
    private:
  		  int x;
  			int y;
};
```

The entries in a class definition is divided into two categories: a ***public*** section available to clients of the class; a ***private*** section restricted to the implementation.



**Implementing Methods**

A class definition appears as a `.h` file that defines the ***interface***. 

Although methods can be implemented within, it is stylistically preferable to define a **separate** `.cpp` file that hides those details. For a method definition, you should implement it using the method name `Point::toString`, just as `__str__` in Python.

Here is a case of the ***accessors/getters*** and ***mutators/setters***. Part of the reason for making instance variables private is to ensure security, with many designed in an even higher level of security by making it **immutable**.



**Constructor**

Class definitions typically include one or more ***constructors***, which are used to initialize an object, like `__init__` in Python. It is *always* called when you create an *instance* of that class. Here are some characteristics:

+ The prototype for a constructor has **no return type** and always has **the same name** as the class. 

+ It may or may not take arguments, with the one taking none a **default** constructor.
+ A single class can have multiple constructors, as a form of *overloading*.



**Initializer List**

An ***initializer list*** is sometimes used in initializing the data members of a class, with the elements in the form of:

+ The *name of a field* in the class, followed by an initializer for that field enclosed in *parentheses*.
+ A superclass constructor (will be discussed later with ***inheritance***).

Here is a comparison between ***initialization by assignments*** and the ***initializer list***:

+ Using assignments, the members are initialized with default values, and then reassigned in the constructor body.

  ```cpp
  Point(int xc = 0, int yc = 0) {
      x = xc;
      y = yc;
  }
  ```

+ Using the initializer list, the members are created and initialized only once, with the given value.

  Also, *constant members* can only be initialized using the *initializer list*, as assigning a value to a constant is not allowed.

  ```cpp
  Point(int xc = 0, int yc = 0) : x(xc), y(yc) {}
  ```



**Detailed Example**

Here is a complete implementation of the `point` class:

+ The `point.h` Interface

  ```cpp
  #ifndef _point_h
  #define _point_h
  
  #include <string>
  class Point {
      public:
      	  /* Constructor to create a Point object. */
    			Point();
          Point(int xc, int yc);
    			/* Returns the x and y coordinates of the point. */
          int getX();
    	    int getY();
    			/* Returns a string representation of the Point (x, y). */
          std::string toString();
      private:
      		int x; // x-coordinate
          int y; // y-coordinate
  };
  
  /* Overloads the << operator to display Point. */
  std::ostream & operator<<(std:ostream & os, Point pt);
  #endif
  ```
  
+ The `point.cpp` Class

  ```cpp
  #include <string>
  #include "point.h"
  #include "strlib.h"
  
  /* Constructors */
  Point::Point() {
      x = 0;
      y = 0;
  }
  Point::Point(int x, int y) {
      x = xc;
      y = yc;
  }
  
  /* Getters */
  int Point::getX() {
      return x;
  }
  int Point::getY() {
      return y;
  }
  
  string Point::toString() {
      return "(" + std::integerToString(x) + "," + std::integerToString(y) + ")"
  }
  
  ostream & operator<<(ostream & os, Point pt) {
      return os << pt.toString();
  }
  ```

  The Constructors can be simplified to 

  ```cpp
  Point(int xc = 0, int yc = 0) {
    x = xc;
    y = yc;
  }
  ```

  or the initializer list:

  ```cpp
  Point(int xc = 0, int yc = 0):x(xc), y(yc) {}
  ```

  However, this approach does not keep the user from calling it with **one** argument.

### 6.2.2 Overloading Operators

One of the most powerful features of C++ is the ability to **extend the existing operators** so that they apply to new types:

![image-20231028142817288](../../../Library/Application Support/typora-user-images/image-20231028142817288.png)

After overloading `<<` in the `Point` class in the prototype of

```cpp
ostream & operator<<(ostream & os, Point pt) {
   return os << pt.toString();
}
```

we will have multiple ways to display the value:

+ Instead of

  ```cpp
  cout << "(" << pt.getX() << "," << pt.getY() << ")";
  ```

+ We could define a `string` representation of the object

  ```cpp
  cout << pt.tostring();  // print(pt.__str__()) in Python
  ```

+ Now we could even, directly

  ```cpp
  cout << pt;  // print(pt) in Python
  ```

Concerning the issues about *pass by reference* `&`:

+ Since stream variables cannot be copied, the `ostream` argument must be passed by *reference*. 
+ The `<<` operator has a chaining behavior of returning the output stream, it must also return its result by *reference*. 

**class methods and free functions**

You can define operators for a class either as ***class methods*** or as ***free functions***. Take it as an example to overload the `==` operator to allow statements of `if (p1 == p2)`:

+ ***class methods:***  When using this style to overload a binary operator, the left operand is *the receiver object* and the right operand is passed as a *parameter*.

  ```cpp
  // in point.h, inside the class Point definition
  bool operator==(Point pt);
  // in point.cpp
  bool Point::operator==(Point pt) {
     return x == pt.x && y == pt.y;
  }
  ```

+ ***free functions:*** The operands for a binary operator are both passed as *parameters* as usual.

  ```cpp
  // in point.h, inside the class Point definition
  friend bool operator==(Point p1, Point p2);
  // in point.h, outside the class Point definition
  bool operator==(Point p1, Point p2);
  // in point.cpp
  bool operator==(Point p1, Point p2) {
     return p1.x == p2.x && p1.y == p2.y;
  }
  ```
  or if public getters are available:
  ```cpp
  // in point.h, outside the class Point definition
  bool operator==(Point p1, Point p2);
  // in point.cpp
  bool operator==(Point p1, Point p2) {
     return p1.getX() == p2.getX() && p1.getY() == p2.getY();
  }

## 6.3 Case: Rational Numbers

Here we define a class called `Rational` that represents *rational numbers*, which are simply the quotient of two integers.

Rational numbers can be useful in cases in which you need exact calculation with fractions like 1/3, even for 1/10 = 0.1 which looks exact (actually an approximation when using `double`).

Rational numbers support the standard arithmetic operations of *addition*, *substraction*, *multiplication* and *division*.

For implementation details, we draw a mind-map like:

+ The private instance variables: *numerator* and *denominator*.

+ The *constructors* for the class are overloaded:
  + With no argument, creates a `Rational` initialized to 0;
  + With one argument, creates a `Rational` equal to that integer;
  + With two arguments, creates a fraction. 

+ The rule in force for expressing a `Rational`:

  + The fraction is always expressed in lowest term.

  + The denominator is always positive.

  + The rational number 0 is always represented as the *fraction* 0/1.

+ The class needs to overload the standard arithmetic operations like  `+`, `-`, `*` and `/`.

**The `rational.h` Interface**

```cpp
/*
 * File: rational.h
 * ----------------
 * This interface exports a class representing rational numbers.
 */

#ifndef _rational_h
#define _rational_h

#include <string>
#include <iostream>

/*
 * Class: Rational
 * ---------------
 * The Rational class is used to represent rational numbers, which
 * are defined to be the quotient of two integers.
 */

class Rational {
public:

/*
 * Constructor: Rational
 * Usage: Rational zero;
 *        Rational num(n);
 *        Rational r(x, y);
 * ------------------------
 * Creates a Rational object.  The default constructor creates the
 * rational number 0.  The single-argument form creates a rational
 * equal to the specified integer, and the two-argument form
 * creates a rational number corresponding to the fraction x/y.
 */

   Rational();
   Rational(int n);
   Rational(int x, int y);
/*
 * Operators: +, -, *, /
 * ---------------------
 * Define the arithmetic operators.
 */

   Rational operator+(Rational r2);
   Rational operator-(Rational r2);
   Rational operator*(Rational r2);
   Rational operator/(Rational r2);

/*
 * Method: toString()
 * Usage: string str = r.toString();
 * ---------------------------------
 * Returns the string representation of this rational number.
 */

   std::string toString();
 
private:

/* Instance variables */

   int num;    /* The numerator of this Rational object   */
   int den;    /* The denominator of this Rational object */

};

/*
 * Operator: <<
 * Usage: cout << rat;
 * -------------------
 * Overloads the << operator so that it is able to display
 * Rational values.
 */

std::ostream & operator<<(std::ostream & os, Rational rat);

#endif
```

**The `rational.cpp` Implementation**

```cpp
/*
 * File: rational.cpp
 * ------------------
 * This file implements the Rational class.
 */

#include <string>
#include <cstdlib>
#include "rational.h"
#include "strlib.h"
using namespace std;

/* Function prototypes */

int gcd(int x, int y); // Why is this protype presented in .cpp file?

/* Constructors */
Rational::Rational() {
   num = 0;
   den = 1;
}

Rational::Rational(int n) {
   num = n;
   den = 1;
}

Rational::Rational(int x, int y) {
   if (x == 0) {
      num = 0;
      den = 1;
   } else {
      int g = gcd(abs(x), abs(y));
      num = x / g;
      den = abs(y) / g;
      if (y < 0) num = -num;
   }
}
/* Implementation of the arithmetic operators */

Rational Rational::operator+(Rational r2) {
   return Rational(num * r2.den + r2.num * den, den * r2.den);
}

Rational Rational::operator-(Rational r2) {
   return Rational(num * r2.den - r2.num * den, den * r2.den);
}

Rational Rational::operator*(Rational r2) {
   return Rational(num * r2.num, den * r2.den);
}

Rational Rational::operator/(Rational r2) {
   return Rational(num * r2.den, den * r2.num);
}
string Rational::toString() {
   if (den == 1) {
      return integerToString(num);
   } else {
      return integerToString(num) + "/" + integerToString(den);
   }
}

int gcd(int x, int y) {
   int r = x % y;
   while (r != 0) {
      x = y;
      y = r;
      r = x % y;
   }
   return y;
}

ostream & operator<<(ostream & os, Rational rat) {
   os << rat.toString();
   return os;
}
```

If we overload it as *free functions*:

```cpp
// in rational.h, inside the class Rational definition
friend Rational operator+(Rational r1, Rational r2);
friend Rational operator-(Rational r1, Rational r2);
friend Rational operator*(Rational r1, Rational r2);
friend Rational operator/(Rational r1, Rational r2);
// in rational.h, outside the class Rational definition
Rational operator+(Rational r1, Rational r2);
Rational operator-(Rational r1, Rational r2);
Rational operator*(Rational r1, Rational r2);
Rational operator/(Rational r1, Rational r2);
// in rational.cpp
Rational operator+(Rational r1, Rational r2) {
   return Rational(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den);
}
Rational operator-(Rational r1, Rational r2) {
   return Rational(r1.num * r2.den - r2.num * r1.den, r1.den * r2.den);
}
Rational operator*(Rational r1, Rational r2) {
   return Rational(r1.num * r2.num, r1.den * r2.den);
}
Rational operator/(Rational r1, Rational r2) {
   return Rational(r1.num * r2.den, r1.den * r2.num);
}
```

