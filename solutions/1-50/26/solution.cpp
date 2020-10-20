#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int len = 0;

    for (int index = 1; index < nums.size(); index++) {
      if (nums[len] != nums[index]) {
        nums[++len] = nums[index];
      }
    }

    return (nums.size() != 0) ? (len + 1) : 0;
  }
};

#ifdef LOCAL_TEST

void dump(vector<int> &nums, int len) {
  cout << "[";
  for (int i = 0; i < nums.size() && i < len; i++) {
    if (i > 0) cout << ", ";
    cout << nums[i];
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums;

  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(2);
  dump(nums, s.removeDuplicates(nums));

  nums.clear();
  nums.push_back(0);
  nums.push_back(0);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(3);
  nums.push_back(4);
  dump(nums, s.removeDuplicates(nums));

  return 0;
}

#endif
