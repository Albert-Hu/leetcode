#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int charToInt(char c) {
    switch (c) {
      case 'I': return 1;
      case 'V': return 5;
      case 'X': return 10;
      case 'L': return 50;
      case 'C': return 100;
      case 'D': return 500;
      case 'M': return 1000;
      default: return 0;
    }
    return 0;
  }

  int romanToInt(string s) {
    bool skip = false;
    int prev = 0, num = 0;

    for (int i = 0; i < s.length(); i++) {
      int v = charToInt(s[i]);
      if (i > 0) {
        if (prev < v) {
          skip = true;
          num += (v - prev);
        } else {
          if (skip) {
            skip = false;
          } else {
            num += prev;
          }
        }
      }
      prev = v;
    }

    if (!skip) {
      num += prev;
    }

    return num;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.romanToInt("III") << endl;
  cout << s.romanToInt("IV") << endl;
  cout << s.romanToInt("IX") << endl;
  cout << s.romanToInt("LVIII") << endl;
  cout << s.romanToInt("MCMXCIV") << endl;

  return 0;
}

#endif
