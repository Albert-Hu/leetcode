#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    if (obstacleGrid.size() == 0)
      return 0;
    if (obstacleGrid[0].size() == 0)
      return 0;
    
    const int m = obstacleGrid.size();
    const int n = obstacleGrid[0].size();
    vector<vector<int> > record(m,vector<int>(n, 0));
    
    record[0][0] = (obstacleGrid[0][0] == 1) ? 0 : 1;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (obstacleGrid[i][j] == 1) continue;
        if (i > 0) record[i][j] += record[i - 1][j];
        if (j > 0) record[i][j] += record[i][j - 1];
      }
    }
    
    return record.back().back();
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int> > obstacleGrid{
    vector<int>{0, 0, 0},
    vector<int>{0, 1, 0},
    vector<int>{0, 0, 0}
  };

  cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;

  return 0;
}

#endif
