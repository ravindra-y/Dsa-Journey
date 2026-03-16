#include <iostream>
using namespace std;

int main() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 9; j++) {
      if ((i + j) % 4 == 0 || (i == 1 && j % 4 == 0))
        cout << "*";
      else
        cout << " ";
    }
    cout << endl;
  }
  return 0;
}


/*

*   *   *
 * * * *
  *   *

*/