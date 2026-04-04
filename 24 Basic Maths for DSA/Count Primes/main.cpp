//? https://leetcode.com/problems/count-primes/description/

#include <iostream>
#include <vector>
using namespace std;

// TODO: solve by Sieve of Eratosthenes theorem

//! complexity -> O[n log (log n)]
int countPrimes(int n) {
  if (n <= 2)
    return 0;

  vector<bool> isPrime(n, true);
  int count = 0;

  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i < n; i++) {
    if (isPrime[i]) {
      count++;
      for (int j = 2 * i; j < n; j = j + i) {
        isPrime[j] = 0;
      }
    }
  }

  return count;
}

int main() {
  int n;
  cout << "Enter n: ";
  cin >> n;

  cout << "Number of prime: " << countPrimes(n) << endl;
  return 0;
}