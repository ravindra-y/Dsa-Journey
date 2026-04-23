// Definition: Wrapping data + methods into a single unit (class)

#include <iostream>
using namespace std;

class Student {
private:
  int marks; // hidden data

public:
  // setter
  void setMarks(int m) {
    marks = m;
  }

  // getter
  int getMarks() {
    return marks;
  }
};

int main() {
  Student s;
  s.setMarks(85);
  cout << "Marks: " << s.getMarks();
}