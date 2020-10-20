#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool increasingTriplet(vector<int>& nums) {
    int i = INT32_MAX, j = INT32_MAX;
    for (auto n : nums) {
      if (n <= i) i = n;
      else if (n <= j) j = n;
      else return true;
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
  nums.push_back(4);
  nums.push_back(5);
  cout << (s.increasingTriplet(nums) ? "true" : "false") << endl;

  nums.clear();
  nums.push_back(5);
  nums.push_back(4);
  nums.push_back(3);
  nums.push_back(2);
  nums.push_back(1);
  cout << (s.increasingTriplet(nums) ? "true" : "false") << endl;

  return 0;
}

#endif
