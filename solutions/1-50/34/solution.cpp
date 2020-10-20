#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int l = 0, r = 0;
    vector<int> ans;

    if (nums.size() == 0) {
      ans.push_back(-1);
      ans.push_back(-1);
      return ans;
    }

    r = nums.size() - 1;
    // find left boundary
    while (l < r) {
      int middle = l + (r - l) / 2;
      if (target >= nums[l] && target <= nums[middle]) {
        r = middle;
      } else {
        l = middle + 1;
      }
    }

    if (target == nums[r]) {
      ans.push_back(r);
      r = nums.size() - 1;
      // find right boundary
      while (l < r) {
        int middle = l + ((r - l) + 1) / 2;
        if (target >= nums[middle] && target <= nums[r]) {
          l = middle;
        } else {
          r = middle - 1;
        }
      }
      ans.push_back(r);
    } else {
      ans.push_back(-1);
      ans.push_back(-1);
    }

    return ans;
  }
};

#ifdef LOCAL_TEST

void dump(vector<int> ans) {
  cout << "[";
  for (int i = 0; i < ans.size(); ++i) {
    if (i > 0) cout << ", ";
    cout << ans[i];
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums;

  nums.push_back(5);
  nums.push_back(7);
  nums.push_back(7);
  nums.push_back(8);
  nums.push_back(8);
  nums.push_back(10);
  dump(s.searchRange(nums, 8));

  nums.clear();
  nums.push_back(5);
  nums.push_back(7);
  nums.push_back(7);
  nums.push_back(8);
  nums.push_back(8);
  nums.push_back(10);
  dump(s.searchRange(nums, 6));
  
  return 0;
}

#endif
