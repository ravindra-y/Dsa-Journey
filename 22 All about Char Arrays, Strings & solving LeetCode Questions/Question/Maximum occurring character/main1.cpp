#include <iostream>
using namespace std;

char getMaxOccCharacter(string str) {
    int freq[26] = {0};

    // Count frequency
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        int index;

        if (ch >= 'a' && ch <= 'z')
            index = ch - 'a';
        else
            index = ch - 'A';

        freq[index]++;
    }

    // Find max occurring character
    int maxFreq = -1;
    int maxIndex = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxIndex = i;
        }
    }

    return 'a' + maxIndex;
}

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;

    cout << "Maximum: " << getMaxOccCharacter(str) << endl;
    return 0;
}
