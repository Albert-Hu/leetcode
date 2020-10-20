#include <iostream>

using namespace std;

class Solution {
public:
  int trailingZeroes(int n) {
    int m = n / 5;
    if (m < 5) return m;
    return m + trailingZeroes(m);
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.trailingZeroes(3) << endl;
  cout << s.trailingZeroes(5) << endl;

  return 0;
}

#endif
