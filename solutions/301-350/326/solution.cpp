#include <iostream>

using namespace std;

class Solution {
public:
#if 1
  bool isPowerOfThree(int n) {
    // 3^19 = 1162261467
    return n > 0 && 1162261467 % n == 0;
  }
#else
  bool isPowerOfThree(int n) {
    while ((n % 3) == 0 && n > 1) {
      n /= 3;
    }
    return (n == 1);
  }
#endif
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << (s.isPowerOfThree(27) ? "true" : "false") << endl;
  cout << (s.isPowerOfThree(0) ? "true" : "false") << endl;
  cout << (s.isPowerOfThree(9) ? "true" : "false") << endl;
  cout << (s.isPowerOfThree(45) ? "true" : "false") << endl;

  return 0;
}

#endif
