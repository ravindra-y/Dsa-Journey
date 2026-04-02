//? https://leetcode.com/problems/valid-palindrome/description/

#include <cctype>
#include <iostream>

using namespace std;

bool isAlphaNum(char ch) {
  return (ch >= '0' && ch <= '9') || (tolower(ch) >= 'a' && tolower(ch) <= 'z');
}

bool isPalindrome(string s) {
  int st = 0, end = s.length() - 1;

  while (st < end) {
    if (!isAlphaNum(s[st])) {
      st++;
      continue; // Skip everything below (Go back to the top of the while loop)
    }
    if (!isAlphaNum(s[end])) {
      end--;
      continue; // Skip everything below (Go back to the top of the while loop)
    }
    if (tolower(s[st]) != tolower(s[end])) {
      return false;
    }
    st++;
    end--;
  }

  return true;
}

int main() {
  string s = "A man, a plan, a canal: Panama";

  if (isPalindrome(s)) {
    cout << "This is palindrome" << endl;
  } else {
    cout << "This is not palindrome" << endl;
  }
  return 0;
}