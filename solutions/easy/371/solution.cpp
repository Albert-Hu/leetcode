#include <iostream>

using namespace std;

class Solution {
public:
  int getSum(int a, int b) {
    unsigned int sum = 0, carry = 0;
    unsigned int x = static_cast<unsigned int>(a);
    unsigned int y = static_cast<unsigned int>(b);
    for (int i = 0; i < 32; i++) {
      int bit = 1 << i;
      sum = sum | (((x & bit) ^ (y & bit)) ^ carry);
      carry = (((x & y) | (x & carry) | (y & carry)) & bit) << 1;
    }
    return static_cast<int>(sum);
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.getSum(1, 2) << endl;
  cout << s.getSum(-2, 3) << endl;

  cout << s.getSum(0, 0) << endl;
  cout << s.getSum(1, 0) << endl;
  cout << s.getSum(0, 1) << endl;
  cout << s.getSum(1, 1) << endl;
  cout << s.getSum(1, -1) << endl;
  cout << s.getSum(-1, -1) << endl;
  cout << s.getSum(-1, 1) << endl;
  cout << s.getSum(-1, 2) << endl;
  cout << s.getSum(-2, 1) << endl;
  cout << s.getSum(1, -3) << endl;
  cout << s.getSum(20, 30) << endl;
  cout << s.getSum(-14, 16) << endl;

  return 0;
}

#endif
