#include <iostream>
using namespace std;

int main() {
  int n = 6;
  int k = 2;

  if (n & (1 << k))
    cout << "Bit is Set";
  else
    cout << "Bit is Not Set";

  return 0;
}