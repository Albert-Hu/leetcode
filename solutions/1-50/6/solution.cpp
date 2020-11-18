#include <iostream>

#ifdef LOCAL_TEST

#include "solution.h"

#else

class Solution {
public:
  string convert(string s, int numRows);
};

#endif

using namespace std;

string Solution::convert(string s, int numRows) {
  string answer;

  if (s.length() == 1 || numRows == 1 || static_cast<unsigned int>(numRows) >= s.length())
    return s;

  for (int i = 0; i < numRows; i++) {
    //unsigned int index = i, next = 0;
    int interval = numRows + numRows - 2;
    int skip[2] = {interval - ((i * 2) % interval), 0};
    cout << skip[0] << ":" << skip[1] << endl;
/*
    while (index < s.length()) {
      answer.push_back(s[index]);
      index += skip[next];
      next = (next + 1) % 1;
    }
*/
  }

  return answer;
}
