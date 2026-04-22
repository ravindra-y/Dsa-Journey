#include <iostream>
using namespace std;

class Student {
private:
  int marks;

public:
  void setMarks(int m) { marks = m; }

  int getMarks() { return marks; }
};

int main() {
  Student s;
  s.setMarks(88);
  cout << s.getMarks();
}