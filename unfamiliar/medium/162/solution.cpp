#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int findPeakElement(vector<int>& nums) {
    return 0;
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
