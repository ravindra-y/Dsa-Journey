#include <iostream>
using namespace std;

int score = 15;

void a(int &i) {
  cout << score << " in a" << endl;
  cout << i << endl << endl;
}

void b(int &i) {
  cout << score << " in b" << endl;
  cout << i << endl << endl;
}

int main() {
  cout << score << " in main" << endl << endl;
  int i = 5;
  a(i);
  b(i);

  return 0;
}