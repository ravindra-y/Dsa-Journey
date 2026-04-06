#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    int* p = arr;   // array name is address of first element

    cout << "Using pointer:\n";
    for (int i = 0; i < 5; i++) {
        cout << *(p + i) << " ";
    }

    return 0;
}


// arr[i]  ==  i[arr]  ==  *(arr + i)  ==  *(p + i)