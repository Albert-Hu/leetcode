#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int longestSubstring(string s, int k) {
    const int len = s.length();
    const int end = len - k;
    int start = 0, maximum = 0;

    while (start <= end) {
      int n = 0, next = start;
      vector<int> count(26, 0);
      for (int i = start; i < len; i++) {
        int c = static_cast<int>(s[i] - 'a');
        count[c]++;
        if (count[c] == 1) n++;
        if (count[c] == k) n--;
        if (n == 0) {
          maximum = max(maximum, (i - start) + 1);
          next = i;
        }
      }
      start = next + 1;
    }

    return maximum;
  }

};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.longestSubstring("aaabb", 3) << endl;
  cout << s.longestSubstring("ababbc", 2) << endl;
  cout << s.longestSubstring("a", 1) << endl;

  return 0;
}

#endif
