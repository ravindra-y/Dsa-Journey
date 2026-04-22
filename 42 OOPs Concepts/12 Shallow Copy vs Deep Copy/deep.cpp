#include <iostream>
using namespace std;

class Deep {
public:
  int *data;

  // Constructor
  Deep(int value) {
    data = new int(value);
  }

  // Deep Copy Constructor
  Deep(const Deep &obj) {
    data = new int(*obj.data); // ✅ new memory allocated
  }

  void show() {
    cout << "Value: " << *data << endl;
  }

  // Destructor
  ~Deep() {
    delete data;
  }
};

int main() {
  Deep obj1(10);
  Deep obj2 = obj1;

  *obj2.data = 20;

  obj1.show(); // No change
  obj2.show();

  return 0;
}