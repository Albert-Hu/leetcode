#include <iostream>
#include <math.h>
using namespace std;

class Solution {
public:
  int titleToNumber(string s) {
    int num = 0;

    for (int i = s.length() - 1, p = 0; i > -1; i--, p++) {
      num = num + ((s[i] - 'A') + 1) * pow(26, p);
    }

    return num;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.titleToNumber("A") << endl;
  cout << s.titleToNumber("AB") << endl;
  cout << s.titleToNumber("ZY") << endl;

  return 0;
}

#endif
