#include <iostream>
using namespace std;

class Student {
public:
  string name;

  Student(string n) { name = n; }
};

int main() {
  Student s("Ravi");
  cout << s.name;
}