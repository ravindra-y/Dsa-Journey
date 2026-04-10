#include <iostream>
using namespace std;

inline int getMax(int& a, int& b) {
  return (a > b) ? a : b;
}

int main() {
  int ans = 0;

  int a = 1;
  int b = 2;

  ans = getMax(a, b);
  cout << ans << endl;

  a = a + 3;
  b = b + 1;

  ans = getMax(a, b);
  cout << ans << endl;

  return 0;
}