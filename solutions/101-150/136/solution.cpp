#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
#if 1
    int result = 0;
    for (auto n : nums)
      result ^= n;
    return result;
#else
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i += 2) {
      if (nums[i] != nums[i - 1]) {
        if (nums[i] != nums[i + 1]) {
          return nums[i];
        } else {
          return nums[i - 1];
        }
      }
    }
    return nums.back();
#endif
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums;

  nums.clear();
  nums.push_back(2);
  nums.push_back(2);
  nums.push_back(1);
  cout << s.singleNumber(nums) << endl;

  nums.clear();
  nums.push_back(4);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(2);
  cout << s.singleNumber(nums) << endl;

  return 0;
}

#endif
