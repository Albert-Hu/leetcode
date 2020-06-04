#include <iostream>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int start = -1, max = 0;
    int table[256];

    for (int i = 0; i < 256; ++i) {
      table[i] = -1;
    }

    for (int i = 0; i < s.size(); ++i) {
      if (table[s[i]] > start) {
        start = table[s[i]];
      }
      table[s[i]] = i;
      if ((i - start) > max) {
        max = i - start;
      }
    }

    return max;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
  cout << s.lengthOfLongestSubstring("bbbbb") << endl;
  cout << s.lengthOfLongestSubstring("pwwkew") << endl;

  return 0;
}

#endif
