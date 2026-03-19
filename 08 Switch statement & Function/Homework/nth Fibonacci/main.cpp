#include <iostream>
using namespace std;

int fibonacci(int index) {
    if (index == 0) return 0;
    if (index == 1) return 1;

    int a = 0, b = 1;

    for (int i = 2; i <= index; i++) {
        int next = a + b;
        a = b;
        b = next;
    }

    return b;
}

int main() {
    int index;
    cout << "Enter index: ";
    cin >> index;
    cout << fibonacci(index) << endl;
    return 0;
}
