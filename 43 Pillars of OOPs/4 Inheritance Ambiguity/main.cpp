// Occurs when same member comes from multiple paths

#include <iostream>
using namespace std;

class A {
public:
  void show() {
    cout << "A\n";
  }
};

class B : public A {};
class C : public A {};

class D : public B, public C {};

int main() {
  D d;
  // d.show(); ❌ ambiguous

  d.B::show(); // ✔ fix
}

int main() {

  return 0;
}