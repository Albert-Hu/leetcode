#include <iostream>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    int start = 0, end = s.length() - 1;

    while (start < end) {
      while (!isAlphanumeric(s[start]) && start < end)
        start++;
      while (!isAlphanumeric(s[end]) && start < end)
        end--;
      if (start < end) {
        if (!isSameLetter(s[start++], s[end--]))
          return false;
      }
    }

    return true;
  }

  bool isSameLetter(char a, char b) {
    if (a >= 'a' && a <= 'z')
      a = (a - 'a') + 'A';
    if (b >= 'a' && b <= 'z')
      b = (b - 'a') + 'A';
    return (a == b);
  }

  bool isAlphanumeric(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
            (c >= '0' && c <= '9'));
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << (s.isPalindrome("A man, a plan, a canal: Panama") ? "true" : "false")
       << endl;
  cout << (s.isPalindrome("race a car") ? "true" : "false") << endl;
  cout << (s.isPalindrome("0P") ? "true" : "false") << endl;

  return 0;
}

#endif
