#include <iostream>
using namespace std;

class Student {
public:
  int marks;
};

int main() {
  // Static
  Student s1;
  s1.marks = 90;

  // Dynamic
  Student *s2 = new Student();
  s2->marks = 85;

  cout << s1.marks << " " << s2->marks;

  delete s2;
}