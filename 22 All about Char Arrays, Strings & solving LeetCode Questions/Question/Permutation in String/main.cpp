//? https://leetcode.com/problems/permutation-in-string/

#include <iostream>
using namespace std;

bool isFreqSame(int freq1[], int freq2[]) {
  for (int i = 0; i < 26; i++) {
    if (freq1[i] != freq2[i]) {
      return false;
    }
  }
  return true;
}

bool checkInclusion(string s1, string s2) {
  int len1 = s1.length(), len2 = s2.length();
  if (len1 > len2)
    return false;

  int freq[26] = {0}, windFreq[26] = {0};

  // Build frequency for s1
  for (char c : s1) {
    freq[c - 'a']++;
  }

  // Build initial window in s2
  for (int i = 0; i < len1; ++i) {
    windFreq[s2[i] - 'a']++;
  }

  // Check first window
  if (isFreqSame(freq, windFreq))
    return true;

  // Slide the window
  for (int i = len1; i < len2; ++i) {
    windFreq[s2[i] - 'a']++;        // add new character
    windFreq[s2[i - len1] - 'a']--; // remove old character

    if (isFreqSame(freq, windFreq))
      return true;
  }

  return false;
}

int main() {

  string s1 = "ab";
  string s2 = "eidbaooo";

  cout << (checkInclusion(s1, s2) ? "Permutation found!" : "Permutation not found!") << endl;

  return 0;
}