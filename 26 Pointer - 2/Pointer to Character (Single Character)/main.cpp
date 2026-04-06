#include <iostream>
using namespace std;

int main() {
    char ch = 'A';
    char *cp = &ch;
    // char *a = "abcde";  ---> 💀 (Don't do this)
    // The compiler assigns a real address to the string literal where its data is stored

    cout << "Character: " << ch << endl;
    cout << "Address of ch: " << (void*)&ch << endl;
    cout << "Value pointed by cp: " << *cp << endl;

    *cp = 'Z';

    cout << "New character: " << ch << endl;

    return 0;
}
