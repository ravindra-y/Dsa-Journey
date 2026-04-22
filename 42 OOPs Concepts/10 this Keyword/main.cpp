#include <iostream>
using namespace std;

class Student {
public:
  int marks;

  void setMarks(int marks) {
    this->marks = marks;
  }
};

int main() {
  Student s;
  s.setMarks(90);
  cout << s.marks;
}