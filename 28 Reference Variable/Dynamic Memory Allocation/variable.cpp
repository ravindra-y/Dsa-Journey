#include <iostream>
using namespace std;

int main() {
    int *num = new int(25);

    cout << *num << endl;

    delete num;   // Always free allocated memory
    return 0;
}