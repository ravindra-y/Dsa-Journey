// https://leetcode.com/problems/reverse-integer/description/

#include <iostream>
#include <climits>
using namespace std;

int reverse(int x) {
    int ans = 0;

    while(x != 0) {

        if(x > (INT_MAX / 10) || x < (INT_MIN / 10)) {
            return 0;
        }

        int digit = x % 10;
        ans = (ans * 10) + digit;
        x /= 10;
    }

    return ans;
}

int main() {
  int n = 123;

  cout << reverse(n);
  return 0;
}