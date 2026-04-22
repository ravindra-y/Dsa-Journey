#include <iostream>
using namespace std;

class Student {
public:
  Student() { cout << "Default Constructor"; }
};

int main() { Student s; }