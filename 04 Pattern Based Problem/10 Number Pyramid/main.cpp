#include <iostream>
using namespace std;

int main() {
  int n = 4;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i - 1; j++)
      cout << " ";

    for (int j = 0; j <= i; j++)
      cout << j + 1 << " ";

    cout << endl;
  }
  return 0;
}


/*

    1
   1 2
  1 2 3
 1 2 3 4

*/