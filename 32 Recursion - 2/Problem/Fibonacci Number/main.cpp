//? https://leetcode.com/problems/fibonacci-number/description/

#include <iostream>
using namespace std;

int fib(int n) {
  // base case
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;

  int ans = fib(n - 1) + fib(n - 2);
  return ans;
}

int main() {

  int n;
  cout << "Enter N: ";
  cin >> n;

  cout << "Result: " << fib(n) << endl;
  return 0;
}


//! visualize using this recursion tree
/*                     fib(4)
                    /      \
               fib(3)      fib(2)
               /    \      /    \
          fib(2)  fib(1) fib(1) fib(0)
          /   \
     fib(1) fib(0)                               */