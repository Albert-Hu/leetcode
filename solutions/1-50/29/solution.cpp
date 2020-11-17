#include <iostream>
using namespace std;

class Solution {
public:
  int divide(int dividend, int divisor) {
    bool sign = ((dividend >> 31) ^ (divisor >> 31));
    int l1, l2, shift;
    long long int a, b, c = 0;

    a = dividend;
    b = divisor;
    a = (a < 0) ? (~(a - 1)) : a;
    b = (b < 0) ? (~(b - 1)) : b;

    if (a < b) {
      return 0;
    }

    l1 = len(a);
    l2 = len(b);
    shift = l1 - l2;

    while (a >= b) {
      long long int tmp = b << shift;
      if (a >= tmp) {
        a -= tmp;
        c = c + ((long long int)1 << shift);
      }
      shift--;
    }

    if ((c >> 31) && !sign) {
      c = 0x7fffffff;
    }

    if (sign) {
      c = ~c + 1;
    }

    return (int)c;
  }

private:
  int len(long long int bits) {
    int l = 31;
    while (!(bits >> l) && l > 0)
      --l;
    return l + 1;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.divide(1, 1) << endl;
  cout << s.divide(10, 3) << endl;
  cout << s.divide(7, -3) << endl;
  cout << s.divide(-7, -3) << endl;
  cout << s.divide(-2147483648, -1) << endl;
  cout << s.divide(-2147483648, 1) << endl;

  return 0;
}

#endif
