#ifdef LOCAL_TEST
#include "solution.h"
#else

class Solution {
public:
  bool isMatch(string s, string p);
};

#endif

bool Solution::isMatch(string s, string p) {
  if (s.length() == 0) {
    for (unsigned int i = 0; i < p.length(); i++) {
      if (p[i] != '*') return false;
    }
    return true;
  } else if (p.length() == 0) {
    return false;
  }

  if (s[0] == p[0] || p[0] == '?')
    return isMatch(s.substr(1), p.substr(1));
  
  if (p[0] == '*') {
    for (unsigned int i = 0; i < s.length(); i++) {
      if (isMatch(s.substr(i + 1), p))
        return true;
    }
    return isMatch(s, p.substr(1));
  }

  return false;
}
