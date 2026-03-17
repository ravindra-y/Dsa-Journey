#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Binary Num: ";
  cin >> n;

  int decNum = 0;
  int pow = 1;

  while(n != 0) {
    int lastDig = n % 10;
    decNum = (lastDig * pow) + decNum;
    n /= 10;
    pow *= 2;
  }

  cout << "Decimal Num: " << decNum << endl;
  return 0;
}