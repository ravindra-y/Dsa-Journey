#include <iostream>
using namespace std;

class Test {
public:
  static int count;
};

int Test::count = 0;

int main() {
  Test t1, t2;
  t1.count = 5;

  cout << t2.count; // shared
}