#include <iostream>
using namespace std;

class Solution {
public:
  int calculate(string s) {
    char op = '+';
    long long int i = 0, r1 = 0, r2 = 0;
    int n = s.size() - 1;

    for (int j = 0; j < s.size(); ++j) {
      char c = s[j];
      if (c >= '0' && c <= '9') {
        i = i * 10 + c - '0';
      }
      if (c == '+' || c == '-' || c == '*' || c == '/' || j == n) {
        switch (op) {
        case '+':
          r1 += i;
          break;
        case '-':
          r1 -= i;
          break;
        case '*':
          r1 *= i;
          break;
        case '/':
          r1 /= i;
          break;
        }
        if (c == '+' || c == '-' || j == n) {
          r2 += r1;
          r1 = 0;
        }
        op = c;
        i = 0;
      }
    }

    return (int)r2;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.calculate("3 + 2 * 2") << endl;
  return 0;
}

#endif
