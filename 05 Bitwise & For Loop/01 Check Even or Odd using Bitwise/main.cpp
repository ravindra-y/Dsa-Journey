#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Enter n: ";
  cin >> n;

  if(n & 1) {
    cout << n << " is ODD" << endl;
  } else {
    cout << n << " is EVEN" << endl;
  }
  return 0;
}

/*
CODE EXPLANATION :
      10 -->  1010                 9 --> 1001
            & 0001                     & 0001
            --------                   --------
              0000 -> So EVEN            0001 -> So ODD
*/