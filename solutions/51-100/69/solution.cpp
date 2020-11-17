#include <iostream>

using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    int left = 1;
    int right = x;

    if (x == 0)
      return 0;
    if (x == 1)
      return 1;

    while (left < right) {
      int middle = left + (right - left) / 2;
      if ((x / middle) >= middle) {
        left = middle + 1;
      } else {
        right = middle;
      }
    }

    return right - 1;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.mySqrt(4) << endl;
  cout << s.mySqrt(8) << endl;

  return 0;
}

#endif
