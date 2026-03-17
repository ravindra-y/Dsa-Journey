#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Enter number: ";
  cin >> n;

  int binary = 0;
  int placeValue = 1;

  while(n != 0) {
    int digit = n & 1;
    binary = (digit * placeValue) + binary;

    n = n >> 1;
    placeValue *= 10;
  }

  cout << "In Binary: " << binary << endl;
  return 0;
}