#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int l = 0, r = nums.size() - 1;

    while (l < r) {
      int middle = l + (r - l) / 2;
      if (target == nums[middle]) {
        return middle;
      }
      if (nums[l] <= nums[middle]) { // ascending order part on left side
        if (target >= nums[l] && target < nums[middle]) {
          r = middle;
        } else {
          l = middle + 1;
        }
      } else { // ascending order part on right side
        if (target > nums[middle] && target <= nums[r]) {
          l = middle + 1;
        } else {
          r = middle;
        }
      }
    }

    return (nums.size() > 0) ? ((target == nums[r]) ? r : -1) : -1;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums;

  nums.push_back(4);
  nums.push_back(5);
  nums.push_back(6);
  nums.push_back(7);
  nums.push_back(0);
  nums.push_back(1);
  nums.push_back(2);
  cout << s.search(nums, 0) << endl;

  nums.clear();
  nums.push_back(4);
  nums.push_back(5);
  nums.push_back(6);
  nums.push_back(7);
  nums.push_back(0);
  nums.push_back(1);
  nums.push_back(2);
  cout << s.search(nums, 3) << endl;

  return 0;
}

#endif
