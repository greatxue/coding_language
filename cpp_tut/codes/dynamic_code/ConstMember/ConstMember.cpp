#include <iostream>
using namespace std;

class A {
public:
    static const int i1 = 0;
    const int i2;
    const double d1 = 0.1;
    const double d2;
    A();
    A(int i, double d);
};

const int A::i1; 

A::A() : i2(1), d2(1.1) {
}

A::A(int i, double d) : i2(i), d2(d) {
}
    
int main()
{
    for (int i = 2; i < 4; i++) {
        A a1;
        A a2(i, i+0.1);
        cout << a1.i1 << '&' << &a1.i1 << endl;
        cout << a1.i2 << '&' << &a1.i2 << endl;
        cout << a1.d1 << '&' << &a1.d1 << endl;
        cout << a1.d2 << '&' << &a1.d2 << endl;
        cout << a2.i1 << '&' << &a2.i1 << endl;
        cout << a2.i2 << '&' << &a2.i2 << endl;
        cout << a2.d1 << '&' << &a2.d1 << endl;
        cout << a2.d2 << '&' << &a2.d2 << endl;
    }
}