#include <iostream>
using namespace std;

class Shallow {
public:
  int *data;

  // Constructor
  Shallow(int value) {
    data = new int(value);
  }

  // Shallow Copy Constructor
  Shallow(const Shallow &obj) {
    data = obj.data; // ❌ same memory shared
  }

  void show() {
    cout << "Value: " << *data << endl;
  }
};

int main() {
  Shallow obj1(10);
  Shallow obj2 = obj1; // Copy constructor called

  *obj2.data = 20;

  obj1.show(); // Unexpected change
  obj2.show();

  return 0;
}