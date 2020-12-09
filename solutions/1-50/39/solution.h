#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void search(vector<int> &candidates, unsigned int start, int target,
              vector<int> &sum, vector<vector<int>> &results);
  vector<vector<int>> combinationSum(vector<int> &candidates, int target);
};

#endif /* _SOLUTION_H_ */
