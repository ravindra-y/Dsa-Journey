#include <iostream>
using namespace std;

void update(int* p) {
    *p = 20;   // change value at the address
}

int main() {
    int x = 10;
    int *ptr = &x;

    update(ptr);
    // update(&x);
    cout << x; // 20
}
