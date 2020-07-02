#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int sum = nums[0];
    int subSum = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      subSum = max(nums[i], (subSum + nums[i]));
      sum = max(sum, subSum);
    }

    return sum;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums;

  nums.push_back(-2);
  nums.push_back(1);
  nums.push_back(-3);
  nums.push_back(4);
  nums.push_back(-1);
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(-5);
  nums.push_back(4);
  cout << s.maxSubArray(nums) << endl;

  return 0;
}

#endif
