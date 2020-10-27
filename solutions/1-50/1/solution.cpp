#include <iostream>
#include <vector>
#include <unordered_map>

#ifdef LOCAL_TEST
#include "solution.h"
#else
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target);
};
#endif

using namespace std;

vector<int> Solution::twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> table;
  vector<int> answer;

  for (unsigned int i = 0; i < nums.size(); i++) {
    if (table.count(target - nums[i]) > 0) {
      answer.push_back(table[target - nums[i]]);
      answer.push_back(i);
      break;
    }
    table[nums[i]] = i;
  }

  return answer;
}
