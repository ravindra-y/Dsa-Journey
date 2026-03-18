// https://leetcode.com/problems/complement-of-base-10-integer/

#include <iostream>
using namespace std;

int bitwiseComplement(int n) {
  if (n == 0) return 1;

  int ans = 0, placeValue = 1;

  while (n != 0) {
      int flippedBit = (n % 2 == 0);  // flip current bit
      ans += placeValue * flippedBit;
      placeValue *= 2;
      n /= 2;
  }
  return ans;
}

int main() {
  int n;
  cout << "Enter a number: ";
  cin >> n;

  cout << "Bitwise Complement: " << bitwiseComplement(n) << endl;
  return 0;
}
