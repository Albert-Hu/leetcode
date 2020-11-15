#include <iostream>
#include <algorithm>
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

#ifdef USE_HASH

/* Use Hash Table */
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

#else /* USE_HASH */

/* Use Sort and Binary Search */
vector<int> Solution::twoSum(vector<int>& nums, int target) {
  vector<int> answer;
  vector<int> indices;

  for (unsigned int i = 0; i < nums.size(); i++) {
    indices.push_back(i);
  }

  sort(indices.begin(), indices.end(), [&](int a, int b) {
    return nums[a] < nums[b];
  });

  for (unsigned int i = 0; i < indices.size(); i++) {
    int n = target - nums[indices[i]];
    auto m = lower_bound(indices.begin() + i + 1, indices.end(), n, [&](int index, int value) {
      return nums[index] < value;
    });

    if (m != indices.end()) {
      if (nums[indices[m - indices.begin()]] == n) {
        answer.push_back(indices[i]);
        answer.push_back(indices[m - indices.begin()]);
        break;
      }
    }
  }

  return answer;
}

#endif /* USE_HASH */
