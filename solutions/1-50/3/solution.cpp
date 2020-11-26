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

#ifdef SOLUTION1
int Solution::lengthOfLongestSubstring(string s) {
  bool table[256];
  unsigned int max_len = 0, begin = 0, end = 0;

  for (int i = 0; i < 256; i++)
    table[i] = false;

  while (begin < s.length()) {
    int index;

    // Find the end of sliding window.
    while (begin < s.length()) {
      index = static_cast<int>(s[begin]);
      if (table[index]) {
        break;
      }
      table[index] = true;
      begin++;
    }

    // Update the maximum length.
    max_len = max(max_len, begin - end);

    // Update the end of sliding windown.
    index = static_cast<int>(s[begin]);
    while (end < begin && table[index]) {
      int remove = static_cast<int>(s[end]);
      table[remove] = false;
      end++;
    }
  }

  return max(max_len, begin - end);
}

#else

int Solution::lengthOfLongestSubstring(string s) {
  int start = -1, max = 0;
  int table[256];

  for (unsigned int i = 0; i < 256; ++i) {
    table[i] = -1;
  }

  for (unsigned int i = 0; i < s.size(); ++i) {
    int index = static_cast<int>(s[i]);
    if (table[index] > start) {
      // Found the repeated character.
      start = table[index];
    }
    // Update the position of the character.
    table[index] = i;
    if ((static_cast<int>(i) - start) > max) {
      max = i - start;
    }
  }

  return max;
}

#endif
