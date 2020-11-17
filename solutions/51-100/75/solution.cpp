#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void sortColors(vector<int> &nums) {
    if (nums.size() == 0)
      return;

    int l = 0, r = nums.size() - 1;

    while (l < r) {
      while (nums[l] == 0 && l < r)
        ++l;
      while (nums[r] != 0 && l < r)
        --r;
      int tmp = nums[l];
      nums[l] = nums[r];
      nums[r] = tmp;
    }

    r = nums.size() - 1;
    while (l < r) {
      while (nums[l] == 1 && l < r)
        ++l;
      while (nums[r] != 1 && l < r)
        --r;
      int tmp = nums[l];
      nums[l] = nums[r];
      nums[r] = tmp;
    }
  }
};

#ifdef LOCAL_TEST

void dump(vector<int> &nums) {
  cout << "[";
  for (int i = 0; i < nums.size(); ++i) {
    if (i > 0)
      cout << ", ";
    cout << nums[i];
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums;

  nums.push_back(2);
  nums.push_back(0);
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(0);
  s.sortColors(nums);
  dump(nums);

  return 0;
}

#endif
