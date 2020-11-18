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

#ifdef SIMULATE

string Solution::convert(string s, int numRows) {
  if (s.length() == 1 || numRows == 1 ||
      static_cast<unsigned int>(numRows) >= s.length())
    return s;

  int index = 0, column = 0;
  int numColumns = s.length();
  string answer;
  vector<string> table(numRows, string(numColumns, ' '));

  while (index < s.length()) {
    for (int row = 0; row < numRows && index < s.length(); row++) {
      table[row][column] = s[index++];
    }
    for (int row = numRows - 2; row > 0 && index < s.length(); row--) {
      table[row][++column] = s[index++];
    }
    column++;
  }

  for (auto line : table) {
    for (auto c : line) {
      if (c != ' ') answer.push_back(c);
    }
  }

  return answer;
}

#else

string Solution::convert(string s, int numRows) {
  if (s.length() == 1 || numRows == 1 ||
      static_cast<unsigned int>(numRows) >= s.length())
    return s;

  string answer;

  for (int i = 0; i < numRows; i++) {
    unsigned int index = i, next = 0;
    int interval = numRows + numRows - 2;
    int skip[2] = {interval - ((i * 2) % interval),
                   interval - ((interval - i * 2) % interval)};

    while (index < s.length()) {
      answer.push_back(s[index]);
      index += skip[next];
      next = (next + 1) % 2;
    }
  }

  return answer;
}

#endif
