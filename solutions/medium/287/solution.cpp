#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findDuplicate(vector<int>& nums) {
    int left = 1, right = nums.size() - 1;

    while (left < right) {
      int middle = left + (right - left) / 2;
      int count = 0;
      for (auto n : nums) {
        if (n <= middle) count++;
      }
      if (count <= middle) {
        left = middle + 1;
      } else {
        right = middle;
      }
    }

    return left;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums;

  nums.clear();
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(2);
  nums.push_back(2);
  cout << s.findDuplicate(nums) << endl;

  nums.clear();
  nums.push_back(3);
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(2);
  cout << s.findDuplicate(nums) << endl;

  return 0;
}

#endif
