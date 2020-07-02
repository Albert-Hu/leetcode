#include <iostream>

using namespace std;

class Solution {
public:
  string countAndSay(int n) {
    if (n == 1) {
      return "1";
    }
    string count = countAndSay(n - 1);
    string say = "";

    int start = 0, end = 1;
    while (end < count.length()) {
      if (count[start] != count[end]) {
        say += to_string(end - start);
        say += count[start];
        start = end;
      }
      end++;
    }
    say += to_string(end - start);
    say += count[start];

    return say;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.countAndSay(1) << endl;
  cout << s.countAndSay(4) << endl;

  return 0;
}

#endif
