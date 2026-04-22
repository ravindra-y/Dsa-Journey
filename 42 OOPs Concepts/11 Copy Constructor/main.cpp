#include <iostream>
using namespace std;

class Student {
public:
  int marks;

  Student(int m) {
    marks = m;
  }

  Student(Student &s) {
    marks = s.marks;
  }
};

int main() {
  Student s1(90);
  Student s2(s1);
  cout << s2.marks;
}