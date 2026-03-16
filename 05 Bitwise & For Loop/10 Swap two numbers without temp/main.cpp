#include <iostream>
using namespace std;

int main() {
  int a = 1;
  int b = 2;

  cout << "Before: " << endl;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << endl;

  a = a ^ b;
  b = a ^ b;
  a = a ^ b;

  cout << "After: " << endl;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  return 0;
}