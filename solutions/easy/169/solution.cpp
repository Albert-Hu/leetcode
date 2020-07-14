#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  int majorityElement(vector<int>& nums) {
    pair<int, int> majority(nums[0], 1);
    map<int, int> count;

    for (auto n : nums) {
      count[n]++;
      if (majority.second < count[n]) {
        majority.first = n;
        majority.second = count[n];
      }
    }
    return majority.first;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums;

  nums.clear();
  nums.push_back(3);
  nums.push_back(2);
  nums.push_back(3);
  cout << s.majorityElement(nums) << endl;

  nums.clear();
  nums.push_back(2);
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(2);
  cout << s.majorityElement(nums) << endl;

  return 0;
}

#endif
