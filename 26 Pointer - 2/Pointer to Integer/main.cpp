#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int *p = &x;   // pointer to int

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Value of p: " << p << endl;
    cout << "Value pointed by p: " << *p << endl;

    *p = 25;   // modify x using pointer

    cout << "New value of x: " << x << endl;

    return 0;
}
