#include <iostream>

#ifdef LOCAL_TEST
#include "solution.h"
#else

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s);
};
#endif

int Solution::lengthOfLongestSubstring(string s) {
  int start = -1, max = 0;
  int table[256];

  for (unsigned int i = 0; i < 256; ++i) {
    table[i] = -1;
  }

  for (unsigned int i = 0; i < s.size(); ++i) {
    int index = static_cast<int>(s[i]);
    if (table[index] > start) {
      start = table[index];
    }
    table[index] = i;
    if ((static_cast<int>(i) - start) > max) {
      max = i - start;
    }
  }

  return max;
}
