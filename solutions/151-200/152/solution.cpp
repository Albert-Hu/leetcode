#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    vector<tuple<int, int, int>> seg = segment(nums);
    int max = (seg.size() > 1) ? 0 : nums[0];

    for (auto t : seg) {
      int m = maximum(nums, t);
      if (m > max)
        max = m;
    }

    return max;
  }

  int maximum(vector<int> &nums, tuple<int, int, int> &t) {
    int start = get<0>(t);
    int end = get<1>(t);
    int count = get<2>(t);
    int max = 1;

    if (start == end)
      return nums[start];

    if ((count % 2) == 0) {
      for (; start <= end; start++) {
        max *= nums[start];
      }
    } else {
      int left = 1, right = 1;

      for (; nums[start] > 0; start++) {
        left *= nums[start];
      }

      for (; nums[end] > 0; end--) {
        right *= nums[end];
      }

      if (start < end) {
        left *= nums[start++];
        right *= nums[end--];
        max = (left < right) ? left : right;
        for (; start <= end; start++) {
          max *= nums[start];
        }
      } else {
        max = (left > right) ? left : right;
      }
    }

    return max;
  }

  vector<tuple<int, int, int>> segment(vector<int> &nums) {
    int start = 0, end = 0, count = 0;
    vector<tuple<int, int, int>> s;

    for (auto n : nums) {
      if (n == 0) {
        if ((end - start) > 0) {
          tuple<int, int, int> t(start, end - 1, count);
          s.push_back(t);
          count = 0;
        }
        start = end + 1;
      } else if (n < 0) {
        count++;
      }
      end++;
    }

    if ((end - start) > 0) {
      tuple<int, int, int> t(start, end - 1, count);
      s.push_back(t);
      count = 0;
      start = end + 1;
    }
    return s;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums;

  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(-2);
  nums.push_back(4);
  cout << s.maxProduct(nums) << endl;

  nums.clear();
  nums.push_back(-2);
  nums.push_back(0);
  nums.push_back(-1);
  cout << s.maxProduct(nums) << endl;

  nums.clear();
  nums.push_back(0);
  nums.push_back(2);
  cout << s.maxProduct(nums) << endl;

  return 0;
}

#endif
