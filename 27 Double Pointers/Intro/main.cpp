#include <iostream>
using namespace std;

int main() {
  int i = 5;
  int *p = &i;
  int **p2 = &p;

  // cout << "value of i: " << i << endl;
  // cout << "value of i: " << *p << endl;
  // cout << "value of i: " << **p2 << endl;

  // cout << "address of i: " << &i << endl;
  // cout << "address of i: " << p << endl;
  // cout << "address of i: " << *p2 << endl;

  cout << &p << endl;
  cout << p2 << endl;

  return 0;
}