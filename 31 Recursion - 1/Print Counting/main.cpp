#include <iostream>
using namespace std;

void printCount(int n) {

  // base case
  if (n <= 0) return;

  // recursive relation
  printCount(n - 1); // Head recursion (1 to n)

  cout << n << " ";

  // printCount(n - 1); // Tail recursion (n to 1)

}

int main() {

  int n;
  cout << "Enter a number: ";
  cin >> n;

  printCount(n);
  return 0;
}