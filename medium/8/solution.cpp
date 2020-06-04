#include <iostream>
using namespace std;

class Solution {
public:
  int myAtoi(string str) {
    bool minus = false;
    int i = 0;
    int integer = 0;

    for (; i < str.size(); ++i) {
      if (str[i] != ' ' && str[i] != '\t') {
        if (str[i] == '+' || str[i] == '-') {
          minus = (str[i] == '-');
          i++;
        }
        break;
      }
    }

    for (; i < str.size(); ++i) {
      if (str[i] < '0' || str[i] > '9') {
        break;
      }
      if (minus) {
        if (integer > 214748364 || (integer == 214748364 && (str[i] - '0') >= 8)) {
          return -2147483648;
        }
      } else {
        if ((integer > 214748364) || (integer == 214748364 && (str[i] - '0') > 7)) { // overflow
          return 2147483647;
        }
      }
      integer = integer * 10 + (str[i] - '0');
    }

    return minus ? -integer : integer;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.myAtoi("42") << endl;
  cout << s.myAtoi("   -42") << endl;
  cout << s.myAtoi("4193 with words") << endl;
  cout << s.myAtoi("words and 987") << endl;
  cout << s.myAtoi("-91283472332") << endl;

  return 0;
}

#endif
