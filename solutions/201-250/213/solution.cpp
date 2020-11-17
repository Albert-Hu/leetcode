#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int rob(vector<int> &nums, int start, int end) {
    int a = 0, b = 0;
    while (start < end) {
      int c = max(nums[start] + a, b);
      a = b;
      b = c;
      start++;
    }
    return b;
  }

  int rob(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    if (nums.size() == 1)
      return nums.front();
    return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int>> nums = {{2, 3, 2}, {1, 2, 3, 1}, {0}};

  for (auto n : nums)
    cout << s.rob(n) << endl;

  return 0;
}

#endif
