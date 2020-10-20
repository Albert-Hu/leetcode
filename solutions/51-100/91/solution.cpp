#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
  int numDecodings(string s) {
    return speedup(s);
  }
private:
  int speedup(string s) {
    int first = 1, second = 1, n = 0;
    for (int i = 0; i < s.length(); ++i) {
      n = (s[i] == '0') ? 0 : second;
      if (i > 0) {
        if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7')) {
          n += first;
        }
      }
      first = second;
      second = n;
    }
    return n;
  }

  int decode(string s) {
    if (s.length() == 0) return 0;
    if (s[0] == '0') return 0;
    if (s.length() == 1) return 1;

    if (record.find(s) != record.end()) {
      return record[s];
    }

    if (s.length() == 2) {
      if (s[0] == '1' || (s[0] == '2' && s[1] < '7')) {
        return s[1] == '0' ? 1 : 2;
      } else {
        return s[1] == '0' ? 0 : 1;
      }
    }

    int n = decode(s.substr(1));
    if (s[0] == '1' || (s[0] == '2' && s[1] < '7')) {
      n = n + decode(s.substr(2));
    }

    record[s] = n;

    return n;
  }
private:
  map<string, int> record;
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution *s;

  s = new Solution;
  cout << s->numDecodings("12") << endl;
  s = new Solution;
  cout << s->numDecodings("226") << endl;
  s = new Solution;
  cout << s->numDecodings("27") << endl;

  return 0;
}

#endif
