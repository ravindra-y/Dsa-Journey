#include <iostream>
#include <cstring>
using namespace std;

char getMaxOccCharacter(char str[]) {
    int freq[26] = {0};

    // Count frequency
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        int index;

        if (ch >= 'a' && ch <= 'z')
            index = ch - 'a';
        else if (ch >= 'A' && ch <= 'Z')
            index = ch - 'A';
        else
            continue;   // ignore non-alphabet characters

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
    char str[1000];

    cout << "Enter string: ";
    cin.getline(str, 1000);

    cout << "Maximum: " << getMaxOccCharacter(str) << endl;

    return 0;
}
