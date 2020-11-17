#ifdef LOCAL_TEST
#include "solution.h"
#else

class Solution {
public:
  vector<int> countBits(int num);
};

#endif

vector<int> Solution::countBits(int num) {
#ifdef ALTERNATIVE_SOLUTION
  vector<int> bits(num + 1, 0);
  for (int i = 1; i <= num; i++) {
    bits[i] = bits[i >> 1] + (i & 1);
  }
#else
  int refStart = 0, refEnd = 1;
  vector<int> bits(num + 1, 0);

  for (int i = 1; i <= num; i++) {
    if (refStart == refEnd) {
      refStart = 0;
      refEnd <<= 1;
    }
    bits[i] = 1 + bits[refStart];
    refStart++;
  }
#endif
  return bits;
}
