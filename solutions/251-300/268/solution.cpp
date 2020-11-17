#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
#if 1
  int missingNumber(vector<int> &nums) {
    int number = nums[0];
    vector<bool> exist(nums.size() + 1, false);
    for (auto n : nums)
      exist[n] = true;
    for (int i = 0; i < exist.size(); i++) {
      if (!exist[i]) {
        number = i;
        break;
      }
    }
    return number;
  }
#else
  int missingNumber(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
      if ((nums[i] - nums[i - 1]) > 1) {
        return nums[i] - 1;
      }
    }
    return (nums[0] != 0) ? 0 : nums.size();
  }
#endif
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums;

  nums.clear();
  nums.push_back(3);
  nums.push_back(0);
  nums.push_back(1);
  cout << s.missingNumber(nums) << endl;

  nums.clear();
  nums.push_back(9);
  nums.push_back(6);
  nums.push_back(4);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(5);
  nums.push_back(7);
  nums.push_back(0);
  nums.push_back(1);
  cout << s.missingNumber(nums) << endl;

  return 0;
}

#endif
