#include <iostream>
using namespace std;

class Test {
public:
  static void show() { cout << "Static Function"; }
};

int main() { Test::show(); }