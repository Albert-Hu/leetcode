#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
#if 1
  int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];
    if (nums.size() == 2) return max(nums[0], nums[1]);

    int a = nums[0], b = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++) {
      int c = max(a + nums[i], b);
      a = b;
      b = c;
    }

    return b;
  }
#else
  int rob(vector<int>& nums) {
    return max(rob(nums, 0), rob(nums, 1));
  }

  int rob(vector<int>& nums, int start) {
    if (record.count(start) > 0) return record[start];

    int maximum = 0;
    for (int i = start; i < nums.size(); i++) {
      int m = nums[i] + rob(nums, i + 2);
      maximum = max(m, maximum);
    }
    record[start] = maximum;

    return maximum;
  }

private:
  map<int, int> record;
#endif
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution *s;
  vector<int> nums;

  nums.clear();
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(1);
  s = new Solution;
  cout << s->rob(nums) << endl;

  nums.clear();
  nums.push_back(2);
  nums.push_back(7);
  nums.push_back(9);
  nums.push_back(3);
  nums.push_back(1);
  s = new Solution;
  cout << s->rob(nums) << endl;

  return 0;
}

#endif
