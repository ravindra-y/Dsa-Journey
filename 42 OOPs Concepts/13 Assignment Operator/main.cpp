#include <iostream>
using namespace std;

class A {
public:
  int x;
};

int main() {
  A a1;
  a1.x = 10;

  A a2;
  a2 = a1;

  cout << a2.x;
}