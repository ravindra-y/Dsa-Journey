#include <iostream>
using namespace std;

int main() {
    char grade;
    cout << "Enter grade (A/B/C/D): ";
    cin >> grade;

    switch (grade) {
        case 'A':
            cout << "Excellent!";
            break;
        case 'B':
            cout << "Good job!";
            break;
        case 'C':
            cout << "Average";
            break;
        case 'D':
            cout << "Needs improvement";
            break;
        default:
            cout << "Invalid grade";
    }

    return 0;
}
