#include <iostream>
using namespace std;

class Test {
public:
  ~Test() { cout << "Destructor Called"; }
};

int main() { Test t; }