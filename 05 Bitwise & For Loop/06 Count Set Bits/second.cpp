#include <iostream>
using namespace std;

int main() {
  int n = 13;
  int count = 0;

  while (n) {
    n = n & (n - 1);
    count++;
  }

  cout << count;

  return 0;
}