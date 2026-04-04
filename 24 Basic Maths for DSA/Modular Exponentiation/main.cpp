//? https://www.naukri.com/code360/problems/modular-exponentiation_1082146

#include <iostream>
using namespace std;

int modularExponentiation(int x, int n, int m) {
  int res = 1;

  while (n > 0) {
    if (n & 1) {
      res = (1LL * (res) * (x) % m) % m;
    }
    x = (1LL * (x) % m * (x) % m) % m;
    n = n >> 1;
  }

  return res;
}

int main() {
  int x = 2, n = 10, m = 1000;
  cout << modularExponentiation(x, n, m);
  return 0;
}