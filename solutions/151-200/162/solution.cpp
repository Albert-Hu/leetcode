#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findPeakElement(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;

    while (left < right) {
      int peek = left + (right - left) / 2;
      if (nums[peek] < nums[peek + 1])
        left = peek + 1;
      else
        right = peek;
    }

    return left;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums;

  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(1);
  cout << s.findPeakElement(nums) << endl;

  nums.clear();
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(5);
  nums.push_back(6);
  nums.push_back(4);
  cout << s.findPeakElement(nums) << endl;

  return 0;
}

#endif
