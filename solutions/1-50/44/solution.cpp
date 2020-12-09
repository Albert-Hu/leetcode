#ifdef LOCAL_TEST
#include "solution.h"
#else

class Solution {
public:
  bool isMatch(string s, string p);
};

#endif

bool Solution::isMatch(string s, string p) {
  int sPrevious = -1, pPrevious = -1;
  unsigned int sIndex = 0, pIndex = 0;

  while (sIndex < s.length()) {
    if (s[sIndex] == p[pIndex] || p[pIndex] == '?') {
      sIndex++;
      pIndex++;
    } else if (p[pIndex] == '*') {
      sPrevious = sIndex;
      pPrevious = pIndex;
      pIndex++;
    } else if (sPrevious > -1) {
      sPrevious++;
      sIndex = sPrevious;
      pIndex = pPrevious + 1;
    } else
      return false;
  }

  while (pIndex < p.length()) {
    if (p[pIndex] != '*')
      break;
    pIndex++;
  }

  return (pIndex == p.length());
}
