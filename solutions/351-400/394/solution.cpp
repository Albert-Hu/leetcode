#include <iostream>
#include <functional>

using namespace std;

class Solution {
public:
  string decodeString(string s) {
    function<int(int,string&)> decodeString = [&](int start, string &result) {
      int times = 0;
      while (start < s.length()) {
        if (s[start] == ']') break;
        if (s[start] >= '0' && s[start] <= '9') {
          times = times * 10 + s[start] - '0';
        } else if (s[start] == '[') {
          string decoded;
          start = decodeString(start + 1, decoded);
          while (times-- > 0) {
            result += decoded;
          }
          times = 0;
        } else {
          result += s[start];
        }
        start++;
      }
      return start;
    };
    string decoded;
    decodeString(0, decoded);
    return decoded;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.decodeString("3[a]2[bc]") << endl;
  cout << s.decodeString("3[a2[c]]") << endl;
  cout << s.decodeString("2[abc]3[cd]ef") << endl;
  cout << s.decodeString("abc3[cd]xyz") << endl;

  return 0;
}

#endif
