#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int start = 0, end = 0;
    map<char, vector<int>> table;

    for (int i = 0; i < s.size(); ++i) {
      table[s[i]].push_back(i);
      for (auto j : table[s[i]]) {
        if ((i == j) || ((i - j) <= (end - start))) {
          break;
        }
        if (isPalindrome(s, j, i)) {
          start = j;
          end = i;
          break;
        }
      }
    }

    return s.empty() ? s : s.substr(start, end - start + 1);
  }

private:
  bool isPalindrome(string &s, int start, int end) {
    while (start < end) {
      if (s[start] != s[end]) {
        return false;
      }
      start++;
      end--;
    }
    return true;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.longestPalindrome("babad") << endl;
  cout << s.longestPalindrome("cbbd") << endl;

  return 0;
}

#endif
