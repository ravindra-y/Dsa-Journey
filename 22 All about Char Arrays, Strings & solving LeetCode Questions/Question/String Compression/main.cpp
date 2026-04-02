//? https://leetcode.com/problems/string-compression/description/

#include <iostream>
#include <vector>
using namespace std;

int compress(vector<char> &chars) {
  int index = 0; // write pointer
  int i = 0;     // read pointer

  while (i < chars.size()) {
    char currentChar = chars[i];
    int count = 0;

    // Count how many times the current character repeats
    while (i < chars.size() && chars[i] == currentChar) {
      i++;
      count++;
    }

    // Write the character
    chars[index++] = currentChar;

    // Write the count digits if count > 1
    if (count > 1) {
      for (char c : to_string(count)) {
        chars[index++] = c;
      }
    }
  }

  return index;
}

int main() {
  vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

  cout << compress(chars) << endl;
  return 0;
}