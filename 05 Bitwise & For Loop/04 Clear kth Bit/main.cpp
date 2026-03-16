#include <iostream>
using namespace std;

int main() {
  int n = 7;
  int k = 1;

  n = n & ~(1 << k);

  cout << n;

  return 0;
}