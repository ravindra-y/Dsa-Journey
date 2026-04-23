#include <iostream>
using namespace std;

class Parent {
public:
  void show() {
    cout << "Parent class\n";
  }
};

class Child : public Parent {
public:
  void display() {
    cout << "Child class\n";
  }
};

int main() {
  Child c;
  c.show(); // inherited
  c.display();
}