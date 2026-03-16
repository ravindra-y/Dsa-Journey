#include <iostream>
using namespace std;

int main() {
  int n = 8;

  if (n > 0 && (n & (n - 1)) == 0)
    cout << "Power of 2";
  else
    cout << "Not Power of 2";

  return 0;
}