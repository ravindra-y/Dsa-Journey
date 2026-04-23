#include <iostream>
using namespace std;

// Single Inheritance
class A {
public:
  void fun() {
    cout << "A\n";
  }
};

class B : public A {};


// Multi-Level Inheritance
class A {
public:
  void funA() {
    cout << "A\n";
  }
};

class B : public A {
public:
  void funB() {
    cout << "B\n";
  }
};

class C : public B {};


// Multiple Inheritance
class A {
public:
  void showA() {
    cout << "A\n";
  }
};

class B {
public:
  void showB() {
    cout << "B\n";
  }
};

class C : public A, public B {};


// Hierarchical Inheritance
class A {
public:
  void show() {
    cout << "Base\n";
  }
};

class B : public A {};
class C : public A {};


// Hybrid Inheritance (Combination)
class A {
public:
  void show() {
    cout << "A\n";
  }
};

class B : public A {};
class C : public A {};

class D : public B, public C {}; // hybrid


int main() {

  return 0;
}