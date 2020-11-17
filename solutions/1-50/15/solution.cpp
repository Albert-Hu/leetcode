#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> matrix;

    if (nums.size() < 3) {
      return matrix;
    }

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
      if (i > 0) {
        if (nums[i - 1] == nums[i]) {
          continue;
        }
      }
      for (int j = i + 1; j < nums.size() - 1; ++j) {
        if (j > (i + 1)) {
          if (nums[j - 1] == nums[j]) {
            continue;
          }
        }
        int target = 0 - (nums[i] + nums[j]);
        int k = binarySearch(nums, j + 1, nums.size() - 1, target);
        if (k > 0) {
          vector<int> ans;
          ans.push_back(nums[i]);
          ans.push_back(nums[j]);
          ans.push_back(nums[k]);
          matrix.push_back(ans);
        }
      }
    }

    return matrix;
  }

private:
  int binarySearch(vector<int> &nums, int start, int end, int target) {
    while (start < end) {
      int middle = start + (end - start) / 2;
      if (target <= nums[middle]) {
        end = middle;
      } else {
        start = middle + 1;
      }
    }
    return nums[start] == target ? start : -1;
  }
};

#ifdef LOCAL_TEST

void dump(vector<vector<int>> matrix) {
  for (int i = 0; i < matrix.size(); ++i) {
    cout << "[";
    for (int j = 0; j < matrix[i].size(); ++j) {
      if (j > 0)
        cout << ", ";
      cout << matrix[i][j];
    }
    cout << "]" << endl;
  }
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums;

  nums.push_back(-1);
  nums.push_back(0);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(-1);
  nums.push_back(-4);

  dump(s.threeSum(nums));

  return 0;
}

#endif
