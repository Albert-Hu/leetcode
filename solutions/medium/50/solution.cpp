#include <iostream>

using namespace std;

class Solution {
public:
  double myPow(double x, int n) {
    if (n == 0) {
      return 1.0;
    }
    if (n == 1) {
      return x;
    }
    if (n == -1) {
      return 1.0 / x;
    }
    if ((n % 2) == 0) {
      x = myPow(x, n / 2);
      x *= x;
    } else {
      if (n < 0) {
        x = myPow(x, n / 2) * myPow(x, (n / 2) - 1);
      } else {
        x = myPow(x, n / 2) * myPow(x, (n / 2) + 1);
      }
    }
    return x;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.myPow(2.0, 10) << endl;
  cout << s.myPow(2.1, 3) << endl;
  cout << s.myPow(2.0, -2) << endl;
  cout << s.myPow(34.00515, -3) << endl;

  return 0;
}

#endif
