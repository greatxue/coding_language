# 2. Functions & Libraries

*Last update: 2023-09-19*

## 2.1 Functions in Programming

A ***function*** is a block of code that has been organized into a separate unit and given a name. The act of using the name to invoke that code is known as *calling* that function, with the variables known as ***parameters*** replaced by ***arguments*** each time. 

When a function is called, the arguments are the data (actual values) you pass into the function's parameters (local variables). Here are their definitions:

+ ***parameter:*** A parameter is a variable in a function declaration and definition, and a placeholder for the argument.
+ ***argument:*** An argument is an expression used when calling the function, and an actualization of the parameter.

The advantages of using functions could be concluded as:

+ **Reuse:** Shortens a program.
+ **Abstraction:** Easier to read.
+ **Decomposition:** Simplifies program maintanance.
+ Top down step-wise refinement.

## 2.2 Functions in C++

Derived from C, the general form of a function looks like:

<img src="https://pic.imgdb.cn/item/65101924c458853aef828d83.png" alt="2-1" style="zoom: 50%;" />

For the syntax within, we have details as

+ **type:** what type the function returns;
+ **name:** the name of the function;
+ **parametre list:** a list of variable declarations;
+ **statements in the function body:** implementation of the function, with at least `return` syntax included.

Specially, functions that return `bool` results are called *predicate functions*, and the function using `void` as the result type (which returns no value at all) are called *procedure* .



**Function Prototype**

A ***function prototype*** is simply the header line of the function followed by a semicolon, which you put in front of the main function, before you actually define the function.

```cpp
#include <iostream>
int add(int a, int b); // function prototype

int main() {
   int result = add(2, 3);
   std::cout << result;
   return 0;
}

int add(int a, int b) {
   return a + b;
}
```

If you always **define functions before you call them**, prototypes are not required. However, this strategy can be counterintuitive by a *top-down design*, and there might be situations where you cannot always define functions before you call them like *mutual recursion*.

```cpp
#include <iostream>

int add(int a, int b) {
    return a + b;
}

int main() {
    int result = add(2, 3);
    std::cout << result;
    return 0;
}
```



**Functions and Algorithms**

Now we continue with **functions and algorithms**. Algorithms for solving a particular problem can vary widely in their efficiency (or complexity), and function could be seen as a structure to express them. Here we will take the example for **greatest common divisor** as an example.


Here is what we call ***Brute-Froce Approach***, which is literally **trying every possibility**, so as to count backwards from the smaller value until you find one that divides evenly into both.

```cpp
int gcd(int x, int y) {
   int guess = (x < y) ? x : y;
   while (x % guess != 0 || y % guess != 0) {
      guess--;
   }
   return guess;
}
```

It is a reminder that `int guess = (x < y) ? x : y;` is a kind of story like:

```cpp
int guess;
if (x < y) {
   guess = x;
}
else guess = y;
```

Also we have the **Euclid’s Algorithm**. A fact is applied: The greatest common divisor of `x` and `y` must also be the greatest common divisor of `y` and the remainder of `x` divided by `y`. 

```cpp
int gcd(int x, int y) {
   int r = x % y;
   while (r != 0) {
      x = y;
      y = r;
      r = x % y;
   }
   return y;
}
```



**Function Overloading**

In C++, Functions can be ***overloaded***, which means that you can define several different functions with the same name as long as the adaptable version can be determined by looking at the ***signature*** (also called the pattern of arguments: **the number and types of the arguments**, but **NOT** the parameter names).

In the example below, which lines are inappropriate? After modification, what is the output?

```cpp
#include <iostream>

int add1(int x);
double add1(double x);   

int main() {
   double x;
   std::cin >> x;
   std::cout << add1(x)/4;
   return 0;
}

double add1(int x) {    
   return x + 1;

int add1(int y) {
   return y + 1;
}
double add1(double x) {
   return x + 1;
}
```

Functions can specify *optional parameters* by including an initializer after the variable name in the function prototype, like 

```cpp
void setMargin(int margin = 72);
```

While giving *default values* to the parameters make them optional:

```cpp
void setInitialLocation(double x = 0, double y = 0);
void setInitialLocation(double x, double y = 0);
void setInitialLocation(double x = 0, double y);   
```

In C++, the specification of the default arguments appears **only** in the *function prototype* and **NOT** in the function definition, and any optional parameters must appear **at the end of the parameter list**. 

What shall we do if we want to keep the users from calling the function with only one argument (*i.e.*, the user can provide either all arguments or no arguments at all)?

```cpp
void setInitialLocation(double x = 0, double y = 0);
```

In the case one parameter is given, it will be assigned to `x`, which may not be the case we are satisfied with. As a subsitution, we may kindly refer to *overloading* for a safer approach: //TODO!!!

```cpp
void setInitialLocation(double x, double y);

void setInitialLocation() {
   setInitialLocation(0, 0);
}
```

## 2.3 Machanics of Calling a Function

When you invoke a function, the following actions occur:

+ The calling function evaluates the argument expressions in its own context.

+ C++ then ***copies*** each argument value into the corresponding parameter variable by order, which is allocated in a newly assigned region of memory called a ***stack frame***. 

+ C++ then evaluates the statements in the function body, using the new stack frame to look up the values of local variables. 

+ When C++ encounters a ***return*** statement, it computes the return value and substitutes that value in place of the call. 

+ C++ then discards the stack frame for the called function and returns to the caller, continuing from where it left off. 
  

<img src="https://pic.imgdb.cn/item/6510193fc458853aef82a9d7.png" alt="2-2" style="zoom: 33%;" />

Under this machanism, given the following function,

```cpp
void swap(int x, int y) {
   int tmp = x;
   x = y;
   y = tmp;
}

int n1 = 1, n2 = 2;
swap(n1, n2);
```

`n1` and `n2` remain the initial values after execution. Why?



**Reference Variables**

If you have worked it out, then we continue with ***reference variables*** in C++. 

A *reference variable* is an alias for an already existing variable, indicated by a prefix `&` character. A reference must be initialized when it is declared, after which it cannot be reassigned.

```cpp
void swap(int & x, int & y) {
   int tmp = x;
   x = y;
   y = tmp;
}
```

To "return more than one value", the `&` could actually be handy. C++ allows callers and functions to share information using a technique known as ***call by reference***, with a single function often having both *value parameters* and *reference parameters*, like

```cpp
int main() {
   double a, b, c, r1, r2;
   getCoefficients(a, b, c);
   solveQuadratic(a, b, c, r1, r2);
   printRoots(r1, r2);
   return 0;
}

void solveQuadratic(double a, double b, double c,
                    double & r1, double & r2) {
   if (a == 0) error("The coefficient a must be nonzero.");
   double disc = b * b - 4 * a * c;
   if (disc < 0) error("This equation has no real roots.");
   double sqrtDisc = sqrt(disc);
   r1 = (-b + sqrtDisc) / (2 * a);
   r2 = (-b - sqrtDisc) / (2 * a);
}
```

In conclusion, a *reference* is a simple reference datatype that is **less powerful but safer** than the ***pointer type*** inherited from C. It can be considered as **a new name for an existing object**, but **NOT** a copy of the object it refers to.

We will delay the discussion of references until when we have a deeper understanding of pointers. 
