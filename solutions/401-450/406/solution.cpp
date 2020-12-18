#ifdef LOCAL_TEST
#include "solution.h"
#else

class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>> &people);
};

#endif

vector<vector<int>> Solution::reconstructQueue(vector<vector<int>> &people) {
  vector<vector<int>> result;

  sort(people.begin(), people.end(), [=](vector<int> &a, vector<int> &b) {
    return (a[0] == b[0]) ? (a[1] < b[1]) : (a[0] > b[0]);
  });

  for (unsigned int i = 0; i < people.size(); i++) {
    result.insert(result.begin() + people[i][1], people[i]);
  }

  return result;
}
