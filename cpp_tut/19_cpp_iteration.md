# 19. Iteration

*Last Update: 23-11-30*

## 19.1 Iterators

In C++ libraries, there are **general** sections for algorithm, functional, iterator, memory, etc.

One of the common operations that clients need to perform when using a collection is to **iterate through the elements**. While it is easy to implement iteration for *vectors* and *grids* using `for` loops, it is less clear for other collection types. 

The modern approach to solving this problem is to use a general tool called an ***iterator*** that delivers the elements of the collection, one at a time:

+ C++11 uses a **range-based for statement** to simplify iterators:

  ```cpp
  for (string key : map) {}
  ```

+ The Stanford libraries provide an alternative like this:

  ```cpp
  foreach (string key in map) {}
  ```

**Using Iterators in C++**

There are several scenarios where iterators are applied:

+ Here is **an iteration through the characters in a string** with *index-based* loop:

  ```cpp
  for (int i = 0; i < str.length(); i++) {
     ... Body of loop that manipulates str[i] ...
  }
  ```

+ For collection classes, the range-based `for` loop looks like:

  ```cpp
  for (string word : english) {
     ... Body of loop involving word ...
  }
  ```

+ The C++ compiler translates the range-based `for` loop using *iterators* (provided by the implementors of the collections.), which is what you would do before C++11:

  ```cpp
  for (Lexicon::iterator it = english.begin(); it != english.end(); it++) {
     ... Body of loop involving *it ...
  }
  ```

Here is an example of *TwoLetterWords*:

```cpp
int main() {
   Lexicon english("EnglishWords.dat");
   for (Lexicon::iterator it = english.begin(); it != english.end(); it++) {
      string word = *it;                   // method 1
      if (word.length() == 2) {
         cout << word << endl;
      }
      if (it->length() == 2) {             // method 2
         cout << *it << endl;
      }
   }
   Lexicon::iterator it = english.begin();
   while (it != english.end()) {
      string word = *it;                   // method 3
      if (word.length() == 2) {
         cout << word << endl;
      }
      if (it->length() == 2) {             // method 4
         cout << *it << endl;
      }
      it++;
   }
   return 0;
}
```

**The C++ Iterator Hierarchy**

<img src="../../../Library/Application Support/typora-user-images/image-20231130003812942.png" alt="image-20231130003812942" style="zoom:50%;" />

**Implementation of iterators**

Every collection class in the STL exports an `iterator` type (a nested type) along with two standard methods that produce iterators:

+ The `begin` method returns an iterator **positioned at the beginning of the collection**.  
+ The `end` method returns an iterator positioned **just past the final element**.

The `Lexicon` class supports only the `InputIterator` level of service, while the iterator for the `Vector` class is a `RandomAccessIterator`. Here is an example of `Vector` iterators:

```cpp
Vector<int>::iterator it = v.end();
while (it != v.begin()) {
   cout << *--it << endl;
}

for (Vector<int>::iterator it = v.begin(); it < v.end(); it += 2) {
   cout << *it << endl;
}
```

Iterators are considerably easier to implement for `Vector` or `HashMap` than they are for most of the other collection classes.

The underlying structure of the vector is defined in terms of a simple dynamic array, and the only state information the iterator needs to maintain is **the current index value** and **a pointer back to the Vector object** itself.

Iterators for tree-structured classes like `Map` turn out to be enormously tricky, mostly because the implementation has to **translate the recursive structure of the data into an iterative form**.

```cpp
template <typename ValueType>
class Vector {
public:
   ... // public methods of class Vector we have studied before
   class iterator { // nested class iterator defined inside class Vector
   public:
      ... // public methods of class iterator
   private:
      const Vector *vp;                  /* Pointer to the Vector object */
      int index;                         /* Index for this iterator      */
      iterator(const Vector *vp, int index) { // private constructor
         this->vp = vp;
         this->index = index;
      }
      friend class Vector;
   } // end of class iterator
   iterator begin() const { // public method of class Vector
      return iterator(this, 0);
   }
   iterator end() const {// public method of class Vector
      return iterator(this, count);
   }
  
private:
   ValueType *array;                    /* A dynamic array of the elements */
   int capacity;                        /* The allocated size of the array */
   int count;                           /* The number of elements in use   */
   ... // private methods of class Vector
}
```

Here is the implementation of the iterator:

```cpp
/*
 * Nested class: iterator
 * ----------------------
 * This nested class implements a standard iterator for the Vector class.
 */

   class iterator {

   public:

/*
 * Implementation notes: iterator constructor
 * ------------------------------------------
 * The default constructor for the iterator returns an invalid iterator
 * in which the vector pointer vp is set to NULL.  Iterators created by
 * the client are initialized by the constructor iterator(vp, k), which
 * appears in the private section.
 */

      iterator() {
         this->vp = NULL;
      }
     
/*
 * Implementation notes: dereference operator
 * ------------------------------------------
 * The * dereference operator returns the appropriate index position in
 * the internal array by reference.
 */

      ValueType & operator*() {
         if (vp == NULL) error("Iterator is uninitialized");
         if (index < 0 || index >= vp->count) error("Iterator out of range");
         return vp->array[index];
      }

/*
 * Implementation notes: -> operator
 * ---------------------------------
 * Overrides of the -> operator in C++ follow a special idiomatic pattern.
 * The operator takes no arguments and returns a pointer to the value.
 * The compiler then takes care of applying the -> operator to retrieve
 * the desired field.
 */

      ValueType* operator->() {
         if (vp == NULL) error("Iterator is uninitialized");
         if (index < 0 || index >= vp->count) error("Iterator out of range");
         return &vp->array[index];
      }

/*
 * Implementation notes: selection operator
 * ----------------------------------------
 * The selection operator returns the appropriate index position in
 * the internal array by reference.
 */

      ValueType & operator[](int k) {
         if (vp == NULL) error("Iterator is uninitialized");
         if (index + k < 0 || index + k >= vp->count) {
            error("Iterator out of range");
         }
         return vp->array[index + k];
      }

/*
 * Implementation notes: relational operators
 * ------------------------------------------
 * These operators compare the index field of the iterators after making
 * sure that the iterators refer to the same vector.
 */

      bool operator==(const iterator & rhs) {
         if (vp != rhs.vp) error("Iterators are in different vectors");
         return vp == rhs.vp && index == rhs.index;
      }

      bool operator!=(const iterator & rhs) {
         if (vp != rhs.vp) error("Iterators are in different vectors");
         return !(*this == rhs);
      }

      bool operator<(const iterator & rhs) {
         if (vp != rhs.vp) error("Iterators are in different vectors");
         return index < rhs.index;
      }

      bool operator<=(const iterator & rhs) {
         if (vp != rhs.vp) error("Iterators are in different vectors");
         return index <= rhs.index;
      }

      bool operator>(const iterator & rhs) {
         if (vp != rhs.vp) error("Iterators are in different vectors");
         return index > rhs.index;
      }

      bool operator>=(const iterator & rhs) {
         if (vp != rhs.vp) error("Iterators are in different vectors");
         return index >= rhs.index;
      }

/*
 * Implementation notes: ++ and -- operators
 * -----------------------------------------
 * These operators increment or decrement the index.  The suffix versions
 * of the operators, which are identified by taking a parameter of type
 * int that is never used, are more complicated and must copy the original
 * iterator to return the value prior to changing the count.
 */

      iterator & operator++() { // ++iterator
         if (vp == NULL) error("Iterator is uninitialized");
         index++;
         return *this;
      }

      iterator operator++(int) { // iterator++
         iterator copy(*this);
         operator++();
         return copy;
      }
      iterator & operator--() { // --iterator
         if (vp == NULL) error("Iterator is uninitialized");
         index--;
         return *this;
      }

      iterator operator--(int) { // iterator--
         iterator copy(*this);
         operator--();
         return copy;
      }

/*
 * Implementation notes: arithmetic operators
 * ------------------------------------------
 * These operators update the index field by the increment value k.
 */

      iterator operator+(const int & k) {
         if (vp == NULL) error("Iterator is uninitialized");
         return iterator(vp, index + k);
      }

      iterator operator-(const int & k) {
         if (vp == NULL) error("Iterator is uninitialized");
         return iterator(vp, index - k);
      }
      int operator-(const iterator & rhs) {
         if (vp == NULL) error("Iterator is uninitialized");
         if (vp != rhs.vp) error("Iterators are in different vectors");
         return index - rhs.index;
      }

/* Private section */

   private:
      const Vector *vp;                  /* Pointer to the Vector object */
      int index;                         /* Index for this iterator      */

/*
 * Implementation notes: private constructor
 * -----------------------------------------
 * The begin and end methods use the private constructor to create iterators
 * initialized to a particular position.  The Vector class must therefore be
 * declared as a friend so that begin and end can call this constructor.
 */

      iterator(const Vector *vp, int index) {
         this->vp = vp;
         this->index = index;
      }

      friend class Vector;

   };

/*
 * Function: begin
 * Usage: Vector<type>::iterator = vec.begin();
 * --------------------------------------------
 * Returns an iterator pointing to the first element.
 */

   iterator begin() const {
      return iterator(this, 0); /* Calling the private constructor */
   }

/*
 * Function: end
 * Usage: Vector<type>::iterator = vec.end();
 * ------------------------------------------
 * Returns an iterator pointing just beyond the last element.
 */

   iterator end() const {
      return iterator(this, count); /* Calling the private constructor */
   }
```

## 19.2 Using functions as data values

**Stored Programming Model**

Before introducing the *mapping functions*, it helps to introduce a more general programming concept as the ability to *use functions as part of the data structure*:

This concept that the code is stored in the same memory as data is called the ***stored programming model***. The important idea is that the code for every C++ function is stored somewhere in memory and therefore has an address.

**Callback Function**

The ability to determine the address of a function makes it possible to **pass functions as parameters to other functions**.

In this example, the function `main` makes two calls to `plot`:

+ The first call passes the address of `sin`, which is **0028**.
+ The second passes the address of `cos`, which is **0044**.

The `plot` function can call this function supplied by the caller. Such functions are known as ***callback functions***

<img src="../../../Library/Application Support/typora-user-images/image-20231130013858938.png" alt="image-20231130013858938" style="zoom: 50%;" />

And the corresponding prototype:

```cpp
void plot(GWindow & gw, double (*fn)(double),
												double minX, double maxX,
												double minY, double maxY);
```

**Function Pointers**

One of the hardest aspects of **function pointers** in C++ is writing the type for the function used in its declaration, but the syntax for declaring function pointers is consistent with others.

| Code                    | Description                                                  |
| ----------------------- | ------------------------------------------------------------ |
| `double x;`             | Declares `x` as a double.                                    |
| `double list[n];`       | Declares `list` as an array of `n` doubles.                  |
| `double *px;`           | Declares `px` as a pointer to a double.                      |
| `double **ppx;`         | Declares `ppx` as a pointer to a pointer to a double.        |
| `double f(double);`     | Declares `f` as a function taking and returning a double.    |
| `double *g(double);`    | Declares `g` as a function taking a double and returning a pointer to a double. |
| `double (*fn)(double);` | Declares `fn` as a pointer to a function taking and returning a double. |

Here is a comparison function, inspired by *the selection sort*:

```cpp
// Here is a comparison function that sorts in ascending order
bool ascending(int x, int y) {
    return x < y; // true if the first element is smaller than the second
}

// Here is a comparison function that sorts in descending order
bool descending(int x, int y) {
    return x > y; // true if the first element is greater than the second
}

// Note our user-defined comparison is the third parameter
void selectionSort(int *array, int size, bool (*comparisonFcn)(int, int)) {
    ...
        if (comparisonFcn(array[currentIndex], array[bestIndex]))
            bestIndex = currentIndex;
    ...
}

int main() {
    int array[9] { 3, 7, 9, 5, 6, 1, 8, 2, 4 };
    // Sort the array in ascending order using the ascending() function
    selectionSort(array, 9, ascending);
    // Sort the array in descending order using the descending() function
    selectionSort(array, 9, descending);
}
```

## 19.3 Mapping Functions

The ability to *work with pointers* to functions offers one solution to the problem of **iterating through the elements of a collection with functions**.

Functions that allow you to call a function on every element in a collection are called ***mapping functions***.

Mapping functions are less convenient than iterators and are consequently used less often, but easier to implement. They are increasingly important to computer science, particularly with the development of **massively parallel applications** like *MapReduce*.

Most collections in the Stanford libraries export the method that calls `fn` on every element of the collection:

```cpp
template <typename ValueType>
void mapAll(void (*fn)(ValueType));
```

**Implementing Mapping Functions**

Here is the `mapAll` function for the `Vector` class:

```cpp
/*
 * Implementation notes: mapAll
 * ----------------------------
 * This method uses a for loop to call fn on every element.
 */

template <typename ValueType>
void Vector<ValueType>::mapAll(void (*fn)(ValueType)) const {
   for (int i = 0; i < count; i++) {
      fn(array[i]);
   }
}
```

Here is the `mapAll` function for the `Map` class:

```cpp
/*
 * Implementation notes: mapAll
 * ----------------------------
 * The exported vertion of mapAll uses a private helper method that takes
 * the tree as an argument and pperdorms a standard inorder traversal,
 * calling fn(key, value) for every key-value pair.
 */

template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::mapAll(void (*fn)(KeyType, ValueType)) const {
   mapAll(root, fn);
}

template <typename KeyType, typename ValueType>
void Map<KeyType, ValueType>::mapAll(BSTNode *t, void (*fn)(KeyType, ValueType)) const {
    if (t != NULL) {
        mapAll(t->left, fn);
        fn(t->key, t->value);
        mapAll(t->right, fn);
    }
}
```

The `mapAll` function is at the same level of the `iterator` class, therefore can get access to the low level data structure directly.

**Using `mapAll` to Iterate**

Now we have multiple ways to iterate through the `Vector`:

+ As an example, you can print all the elements of an integer vector `Vector<int> v` using an iterator, where `printInt` is defined separately:

  ```cpp
  void printInt(int n) { cout << n << endl; }
  Vector<int> v;
  for (Vector<int>::iterator it = v.begin();
     it < v.end(); it ++) {
     printInt(*it);
  }
  ```

+ If a mapping function is defined in `Vector` which can perform `fn` on every element of the collection

  ```cpp
  template <typename ValueType>
  void mapAll(void (*fn)(ValueType));
  ```

  then you can simply call the following

  ```cpp
  v.mapAll(printInt); 
  ```

Here is another example of the `Lexicon` class:

+ The `Lexicon` class exports a mapping function called `mapAll` with the signature

  ```cpp
  void mapAll(void (*fn)(string));
  ```

+ The existence of `mapAll` in the `Lexicon` class makes it possible to recode the `TwoLetterWords` program as

  ```cpp
  void printTwoLetterWords(string word) {
     if (word.length() == 2) { cout << word << endl; }
  }
  int main() {
     Lexicon english("EnglishWords.dat");
     english.mapAll(printTwoLetterWords);
  }
  ```

  as opposed to an iterator

  ```cpp
  for (Lexicon::iterator it = english.begin();
     it != english.end(); it++) {
     printTwoLetterWords(*it);
  }
  ```

## 19.4 Encapsulating data with functions

The biggest problem with using *mapping functions* is that it is difficult to pass client information from the client back to the callback function. There are two strategies for this:

+ Passing an additional argument to the mapping function, which is then included in the set of arguments to the callback function (overloading `mapAll` in many forms).

+ Passing a ***function object*** or ***functors*** to the mapping function. A *function object* is simply any object that overloads the function-call operator, which is designated in C++ as `operator()`.

Here is the further implementation of the `listKLetterWords` class:

```cpp
class ListKLetterWords {
public:
   ListKLetterWords(int k) {
      this->k = k;
   }
   int operator()(string word) {
      if (word.length() == k) {
         cout << word << endl;
      }
   }
private:
   int k;     /* Length of desired words */
};
void listWordsOfLengthK(const Lexicon & lex, int k) {
   ListKLetterWords fn = ListKLetterWords(k);
   lex.mapAll(fn);
}
```

Here is an example of programming with *functors*:

```cpp
int main() {
    AddKFunction add1 = AddKFunction(1);
    AddKFunction add17 = AddKFunction(17);
    cout << "add1(100) -> " << add1(100) << endl;
    cout << "add17(25) -> " << add17(25) << endl;
    return 0;
}

/*
 * Class: AddKFunction
 * -------------------
 * This class defines a function object that takes a single integer x and
 * computes the value x + k, where k is a constant specified by the client.
 */

class AddKFunction {

public:

/*
 * Constructor: AddKFunction
 * Usage: AddKFunction addk = AddKFunction(k);
 * -------------------------------------------
 * Creates a function object that adds k to its argument.
 */

   AddKFunction(int k) { this->k = k; }

/*
 * Operator: ()
 * ------------
 * Defines the behavior of an AddKFunction object when it is called
 * as a function.
 */

   int operator()(int x) { return x + k; }

private:

   int k;     /* Instance variable that keeps track of the increment value */

};
```

## 19.5 Methods in the `algorithm` Library

Besides their original purpose of stepping through the elements of a collection, so many of the functions in the Standard Template Library take iterators as parameters:

+ To sort all the elements of a vector `v`, you call

  ```cpp
  sort(v.begin(), v.end());
  ```

+ To sort only the first `k` elements of `v`, you could call

  ```cpp
  sort(v.begin(), v.begin() + k);
  ```

One more way to print *two-letter words*:

```cpp
void printTwoLetterWords(string word) {
   if (word.length() == 2) {
      cout << word << endl;
   }
}

int main() {
   Lexicon english("EnglishWords.dat");
   for_each(english.begin(), english.end(), printTwoLetterWords);
   return 0;
}
```

The callback function can also be a function object:

```cpp
for_each(english.begin(), english.end(), ListKLetterWords(k));
```

**Selection sort**

Here is the advancement of the *selection sort*:

```cpp
void sort(Vector<int> & vec) {
   int n = vec.size();
   for (int lh = 0; lh < n; lh++) {
      int rh = lh;
      for (int i = lh + 1; i < n; i++) {
         if (vec[i] < vec[rh]) rh = i;
      }
      int temp = vec[lh];
      vec[lh] = vec[rh];
      vec[rh] = temp;
   }
}
```

Selection sort using iterators and the `algorithm` library:

```cpp
void sort(Vector<int> & vec) {
   for (Vector<int>::iterator lh = vec.begin(); lh != vec.end(); lh++) {
      Vector<int>::iterator rh = min_element(lh, vec.end());
      iter_swap(lh, rh);
   }
}
```

In a more compact form:

```cpp
void sort(Vector<int> & vec) {
   for (Vector<int>::iterator lh = vec.begin(); lh != vec.end(); lh++) {
      iter_swap(lh, min_element(lh, vec.end()));
   }
}
```

If indeed you can convert a sequence of **procedural-style statements** into a sequence of embedded calls to a certain set of functions, you get a new style or paradigm of programming, called ***functional programming***.

**More methods in `algorithm` Library**

| Function                                 | Description                                                  |
| ---------------------------------------- | ------------------------------------------------------------ |
| `max(x, y)`                              | Returns the greater of x and y.                              |
| `min(x, y)`                              | Returns the lesser of x and y.                               |
| `swap(x, y)`                             | Swaps the reference parameters x and y.                      |
| `iter_swap(i1, i2)`                      | Swaps the values addressed by the iterators i1 and i2.       |
| `binary_search(begin, end, value)`       | Returns true if the iterator range contains the specified value. |
| `copy(begin, end, out)`                  | Copies the iterator range to the output iterator.            |
| `count(begin, end, value)`               | Counts the number of values in the iterator range that are equal to value. |
| `fill(begin, end, value)`                | Sets every element in the iterator range to value.           |
| `find(begin, end, value)`                | Returns an iterator to the first element in the iterator range that is equal to value. |
| `merge(begin1, end1, begin2, end2, out)` | Merges the sorted input sequences into the output iterator.  |
| `min_element(begin, end)`                | Returns an iterator to the smallest element in the iterator range. |
| `max_element(begin, end)`                | Returns an iterator to the largest element in the iterator range. |
| `random_shuffle(begin, end)`             | Randomly reorders the elements in the iterator range.        |
| `replace(begin, end, old, new)`          | Replaces all occurrences of old with new in the iterator range. |
| `reverse(begin, end)`                    | Reverses the elements in the iterator range.                 |
| `sort(begin, end)`                       | Sorts the elements in the iterator range.                    |
| `for_each(begin, end, fn)`               | Calls fn on every value in the iterator range.               |
| `count_if(begin, end, pred)`             | Returns the number of elements in the iterator range for which pred is true. |
| `replace_if(begin, end, pred, new)`      | Replaces every element in the iterator range for which pred is true by new. |
| `partition(begin, end, pred)`            | Reorders the elements in the iterator range so that the pred elements come first. |

## 19.6 Functional Programming

By including certain templates and function objects, it is possible to adopt a programming style that is remarkably close to the *functional programming* model, with the following properties:

+ Programs are expressed in the form of **nested function calls** that perform the necessary computation without performing any operations (such as assignment).

+ Functions are **data values** and can be manipulated by the programmer just like other data values.

Here is a illustration of the *functional* paradigm:

+ Make a *procedural* dumpling:

  ```
  dough = whisk(flour, water)
  filling = mix(meat, vegetable)
  dumpling = stuff(dough, filling)
  steamed dumpling = steam(dumpling)
  ```

+ Make a *functional* dumpling:

  ```
  steam(stuff(whisk(flour, water), mix(meat, vegetable)))
  ```

**Using the General Section**

Through the `<functional>` interface, we have two categories as a representation:

+  The template class `binary_function` that takes two arguments;
+  The `unary_function` that takes a single argument.

`bind2nd` returns a unary function object that **calls a binary function object with its second parameter bound to a value**. 

The following expression returns a unary function object that adds the constant 1 to its argument:

```cpp
bind2nd(plus<int>(), 1)
```

The functions in the `algorithm` library involve sorting (including `sort`, `merge`, `binary_search`, `min_element`, `max_element`) and **take an optional functional parameter** that defines the ordering. 

By default, this parameter is generated by calling the `less` constructor appropriate to the value type. You can arrange an integer vector `v` in reverse order:

```cpp
sort(vec.begin(), vec.end(), greater<int>());
```

The clients can supply their own function pointer or function object instead. That function, which is called a ***comparison function***, should take two arguments of the value type and return a Boolean value, which is `true` if the first value should come before the second.

**More methods in `functional` Library**

| Function                                          | Description                                                  |
| ------------------------------------------------- | ------------------------------------------------------------ |
| `binary_function<ArgType1, ArgType2, ResultType>` | Superclass for functions that take the two argument types and return a result type. |
| `unary_function<ArgType, ResultType>`             | Superclass for functions that take one argument type and return a result type. |
| `plus<Type>`                                      | Binary function implementing the `+` operator.               |
| `minus<Type>`                                     | Binary function implementing the `-` operator.               |
| `multiplies<Type>`                                | Binary function implementing the `*` operator.               |
| `divides<Type>`                                   | Binary function implementing the `/` operator.               |
| `modulus<Type>`                                   | Binary function implementing the `%` operator.               |
| `negate<Type>`                                    | Unary function implementing the `-` operator.                |
| `equal_to<Type>`                                  | Function class implementing the `==` operator.               |
| `not_equal_to<Type>`                              | Function class implementing the `!=` operator.               |
| `less<Type>`                                      | Function class implementing the `<` operator.                |
| `less_equal<Type>`                                | Function class implementing the `<=` operator.               |
| `greater<Type>`                                   | Function class implementing the `>` operator.                |
| `greater_equal<Type>`                             | Function class implementing the `>=` operator.               |
| `logical_and<Type>`                               | Function class implementing the `&&` operator.               |
| `logical_or<Type>`                                | Function class implementing the `||` operator.               |
| `logical_not<Type>`                               | Function class implementing the `!` operator.                |
| `bind1st(fn, value)`                              | Returns a unary counterpart to the binary `fn` in which the first argument is `value`. |
| `bind2nd(fn, value)`                              | Returns a unary counterpart to `fn` in which the second argument is `value`. |
| `not1(fn)`                                        | Returns a unary predicate function which has the opposite result of `fn`. |
| `not2(fn)`                                        | Returns a binary predicate function which has the opposite result of `fn`. |
| `ptr_fun(fnptr)`                                  | Converts a function pointer to the corresponding function object. |

Here is an example of **counting the number of negative values in an integer vector `v`**:

+ The *procedural* program:

  ```cpp
  int neg = 0;
  for (Vector<int>::iterator it = v.begin(); it != v.end(); it++) {
      if (*it < 0) neg++;
  }
  ```

+ The *functional* program using `algorithm` and `functional` libraries and iterators:

  ```cpp
  int neg = count_if(v.begin(), v.end(), bind2nd(less<int>(), 0));
  ```

+ The *object-oriented programming* program:

  We may maintain a private data member `neg` in the collection class and update it in the member methods whenever necessary, if the efficiency of counting `neg` is crucial. 

  ```cpp
  template <typename ValueType>
  class Vector {
  ...
  private:
  ...
     ValueType *array;     /* Dynamic array of the elements    */
     int capacity;         /* Allocated size of that array     */
     int count;            /* Current count of elements in use */
     int neg;              /* The number of negative elements  */
  ...
  }
  ```

---



