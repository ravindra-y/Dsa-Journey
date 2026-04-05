#include <iostream>
using namespace std;

int main() {
  int num = 5;

  cout << num << endl;

  // address of Operator -> &

  cout << "Address of num: " << &num << endl;

  int *ptr = &num;

  cout << "Value: " << *ptr << endl;
  cout << "Address: " << ptr << endl;

  double d = 4.3;
  double *p2 = &d;

  cout << "Value: " << *p2 << endl;
  cout << "Address: " << p2 << endl;

  cout << "size of integer: " << sizeof(num) << endl;
  cout << "size of pointer: " << sizeof(ptr) << endl;

  return 0;
}