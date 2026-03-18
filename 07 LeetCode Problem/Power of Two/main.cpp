// https://leetcode.com/problems/power-of-two/description/

#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    if (n <= 0) {
        return false;
    }
    // A power of two has only ONE '1' in its binary representation
    return (n & (n - 1)) == 0;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isPowerOfTwo(n)) {
        cout << n << " is a power of two." << endl;
    } else {
        cout << n << " is NOT a power of two." << endl;
    }

    return 0;
}
