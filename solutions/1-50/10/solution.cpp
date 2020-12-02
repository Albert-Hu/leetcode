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
    if ((p.length() % 2) != 0)
      return false;
    for (unsigned int i = 1; i < p.length(); i += 2) {
      if (p[i] != '*')
        return false;
    }
    return true;
  } else if (p.length() == 0) {
    return false;
  }

  bool result = false;
  bool isStar = (p.length() > 1) ? (p[1] == '*') : false;

  if (isStar) {
    string nextPattern = p.substr(2);
    result = isMatch(s, nextPattern);
    for (unsigned int i = 0; i < s.length() && !result; i++) {
      if (s[i] != p[0] && p[0] != '.') {
        break;
      } else {
        result = isMatch(s.substr(i + 1), nextPattern);
      }
    }
  } else {
    if (s[0] != p[0] && p[0] != '.') {
      result = false;
    } else {
      result = isMatch(s.substr(1), p.substr(1));
    }
  }

  return result;
}
