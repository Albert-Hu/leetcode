#ifdef LOCAL_TEST
#include "solution.h"
#else

class Solution {
public:
  int firstMissingPositive(vector<int> &nums);
};

#endif

int Solution::firstMissingPositive(vector<int> &nums) {
  vector<bool> missed(300, true);

  for (auto n : nums) {
    if (n > 0 && n < 301)
      missed[n - 1] = false;
  }

  for (unsigned int i = 0; i < missed.size(); i++) {
    if (missed[i])
      return (i + 1);
  }

  return 301;
}
