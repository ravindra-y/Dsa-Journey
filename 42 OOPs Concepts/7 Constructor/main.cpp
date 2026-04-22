#include <iostream>
using namespace std;

class Student {
public:
  Student() { cout << "Constructor Called"; }
};

int main() { Student s1; }