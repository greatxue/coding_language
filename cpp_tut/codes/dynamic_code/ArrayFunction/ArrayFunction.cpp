// Example program
#include <iostream>
using namespace std;

void f(int list[]){
    cout << list[0] << endl;
    cout << list << endl;
    cout << &list << endl;
    cout << sizeof list[0] << endl;
    cout << sizeof list << endl;
    cout << sizeof &list << endl;
}

int main()
{
    int list[5] = {1,2,3,4,5};
    cout << list[0] << endl;
    cout << list << endl;
    cout << &list << endl;
    cout << sizeof list[0] << endl;
    cout << sizeof list << endl;
    cout << sizeof &list << endl;
    f(list);
    int *plist = list;
    cout << plist[0] << endl;
    cout << plist << endl;
    cout << &plist << endl;
    cout << sizeof plist[0] << endl;
    cout << sizeof plist << endl;
    cout << sizeof &plist << endl;
    f(plist);
    plist = new int[5];
    cout << plist[0] << endl;
    cout << plist << endl;
    cout << &plist << endl;
    cout << sizeof plist[0] << endl;
    cout << sizeof plist << endl;
    cout << sizeof &plist << endl;
    f(plist);
}