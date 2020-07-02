#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
  int reverse(int x) {
    bool isNegative = (x < 0);
    long long int reversedX = 0;
    string str;

    if (x == numeric_limits<int>::min())
      return 0;

    if (isNegative) x = -x;

    while (x > 0) {
      reversedX = reversedX * 10 + (x % 10);
      x /= 10;
    }

    if (isNegative) reversedX = -reversedX;

    return (reversedX > numeric_limits<int>::max() || reversedX < numeric_limits<int>::min()) ? 0 : static_cast<int>(reversedX);
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.reverse(123) << endl;
  cout << s.reverse(-123) << endl;
  cout << s.reverse(120) << endl;

  return 0;
}

#endif
