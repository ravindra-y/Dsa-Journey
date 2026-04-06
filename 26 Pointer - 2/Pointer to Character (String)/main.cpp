#include <iostream>
using namespace std;

int main() {
    char str[] = "Hello";
    char *p = str;   // points to first character

    cout << "First char: " << *p << endl;
    cout << "Second char: " << *(p + 1) << endl;
    cout << p << endl;

    // while (*p != '\0') {
    //     cout << *p << " ";
    //     p++;
    // }

    return 0;
}

// (void*) is used so the address prints correctly (otherwise cout treats char* as a string).