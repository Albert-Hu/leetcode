#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1]) return true;
    }
    return false;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums;

  nums.clear();
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(1);
  cout << (s.containsDuplicate(nums) ? "true" : "false") << endl;

  nums.clear();
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);
  cout << (s.containsDuplicate(nums) ? "true" : "false") << endl;

  nums.clear();
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(3);
  nums.push_back(2);
  nums.push_back(4);
  nums.push_back(2);
  cout << (s.containsDuplicate(nums) ? "true" : "false") << endl;

  return 0;
}

#endif
