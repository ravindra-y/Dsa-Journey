#include <iostream>
using namespace std;

class Student {
public:
  int a;
  int b;
};

int main() {
  Student s1;
  cout << sizeof(s1); // memory size
}