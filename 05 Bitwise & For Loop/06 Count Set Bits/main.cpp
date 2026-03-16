#include <iostream>
using namespace std;

int main() {
  int n = 13;
  int count = 0;

  while (n) {
    count += n & 1;
    n = n >> 1;
  }

  cout << count;

  return 0;
}