# 6. Designing Classes

## 6.1 Data Types in C++

There are numerous data types provided in C++:

+ **Primitive types:** basic data types including but not limited to `int`, `double`, `bool` (`true` or `false`) and `char` (representing a single ASCII character).
+ **Collections**
+ **Compound data types:** more complex data types like **Enumerated types**, **Structures** and **Classes** (like C++ strings and streams)

### 6.1.1 Enumerated types

An enumerated type can be roughly considered as a subset of `int` with special names:

```cpp
// automatically assigned by numbers from 0:
enum Direction { NORTH, EAST, SOUTH, WEST }; 
// could be assigned by yourself as well:
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
In C, structures define the representation of a compound value, while functions define operations on these data. 

In C++, these two ideas are integrated. Most data structures are represented as ***objects*** based on the idea of a **class**. The class definition specifies the representation of the object by naming its **fields** or **instance variables**, and the behavior of the object by providing a set of **methods**.

New objects are created as **instances** of a particular class, and the creation of new instances is called **instantiation**.

For example, you could represent points using a Class like:

```cpp
class Point {
    public:
    private:
  		  int x;
  			int y;
};
```

The entries in a class definition is divided into two categories: a **public** section available to clients of the class; a **private** section restricted to the implementation.

**Implementing Methods**

A class definition appears as a `.h` file that defines the ***interface***. 

Although methods can be implemented within, it is stylistically preferable to define a **separate** `.cpp` file that hides those details. For a method definition, you should implement it using the method name `Point::toString`, just as `__str__` in Python.

Here is a case of the ***accessors/getters*** and ***mutators/setters***. Part of the reason for making instance variables private is to ensure security, with many designed in an even higher level of security by making it **immutable**.

**Constructor**

Class definitions typically include one or more ***constructors***, which are used to initialize an object, like `__init__` in Python. It is *always* called when you create an **instance** of that class. Here are some characteristics:

+ The prototype for a constructor has **no return type** and always has **the same name** as the class. 

+ It may or may not take arguments, with the one taking none a ***default constructor***.
+ A single class can have multiple constructors, as a form of **overloading**.

**Initializer List**

An ***initializer list*** is sometimes used in initializing the data members of a class, with the elements in the form of:

+ The **name of a field** in the class, followed by an initializer for that field enclosed in *parentheses*.
+ A superclass constructor (will be discussed later with ***inheritance***).

Here is a comparison between *initialization by assignments* and the *initializer list*:

+ Using assignments, the members are initialized with default values, and then reassigned in the constructor body.

  ```cpp
  Point(int xc = 0, int yc = 0) {
      x = xc;
      y = yc;
  }
  ```

+ Using the initializer list, the members are created and initialized only once, with the given value.

  Also, **Constant members** can only be initialized using the *initializer list*, as assigning a value to a constant is not allowed.

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

When defining operators for a class, you can write them either as **class methods**  or as **free functions**.

+ **Class methods:** The operator is part of the class and therefore **has free access** to the *private* instance. When using this style to overload a binary operator, the left operand is *the receiver object* and the right operand is passed as a *parameter*.

+ **Free functions:** The operator as a **free function** often produces code that is easier to read, with the operands for a binary operator are both passed as *parameters* as usual.

  It is a reminder that the **operator function** must be designated as a `friend` to refer to the private data that do not have public getters.
