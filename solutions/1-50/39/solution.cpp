#ifdef LOCAL_TEST
#include "solution.h"
#else

class Solution {
public:
  void search(vector<int> &candidates, unsigned int start, int target,
              vector<int> &sum, vector<vector<int>> &results);
  vector<vector<int>> combinationSum(vector<int> &candidates, int target);
};

#endif

void Solution::search(vector<int> &candidates, unsigned int start, int target,
                      vector<int> &sum, vector<vector<int>> &results) {
  while (start < candidates.size()) {
    if (target < candidates[start])
      break;
    sum.push_back(candidates[start]);
    if ((target - candidates[start]) == 0) {
      results.push_back(sum);
    } else {
      search(candidates, start, target - candidates[start], sum, results);
    }
    sum.pop_back();
    start++;
  }
}

vector<vector<int>> Solution::combinationSum(vector<int> &candidates,
                                             int target) {
  vector<int> sum;
  vector<vector<int>> results;

  sort(candidates.begin(), candidates.end());

  search(candidates, 0, target, sum, results);

  return results;
}
