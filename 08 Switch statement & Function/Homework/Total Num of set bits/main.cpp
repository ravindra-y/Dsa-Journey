#include <iostream>
using namespace std;

int setBits(int n, int m) {
    int count = 0;
    while (n || m) {
        count += (n & 1) + (m & 1);
        n >>= 1;
        m >>= 1;
    }
    return count;
}

int main() {
    cout << setBits(2, 3) << endl;
    return 0;
}
