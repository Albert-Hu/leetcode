#include <iostream>
#include <vector>

#ifdef LOCAL_TEST
#include "solution.h"
#else
class Solution {
public:
  Solution();
  int integerBreak(int n);
private:
  vector<int> integers;
};
#endif

using namespace std;

Solution::Solution() {
  int count = 56;

  /* The result of number 0. */
  integers.push_back(0);
  /* The result of number 1. */
  integers.push_back(0);
  /* The result of number 2. */
  integers.push_back(1);
  /* Initialize the remaining numbers. */
  while (count-- > 0)
    integers.push_back(-1);
}

int Solution::integerBreak(int n) {
  if (integers[n] > -1)
    return integers[n];
  
  int maximum = 0;
  int left = 1, right = n - 1;

  while (left <= right) {
    int l = integerBreak(left);
    int r = integerBreak(right);
    maximum = max(maximum, max(left, l) * max(right, r));
    left++, right--;
  }

  integers[n] = maximum;

  return maximum;
}
