// Definition: Showing only essential details, hiding implementation

#include <iostream>
using namespace std;

class Shape {
public:
  virtual void draw() = 0; // pure virtual function
};

class Circle : public Shape {
public:
  void draw() {
    cout << "Drawing Circle\n";
  }
};

int main() {
  Shape *s;
  Circle c;

  s = &c;
  s->draw();
}