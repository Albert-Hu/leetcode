#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[i].size(); j++) {
        if (i == 0) {
          if (j > 0) {
            grid[i][j] += grid[i][j - 1];
          }
        } else {
          if (j > 0) {
            grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
          } else {
            grid[i][j] += grid[i - 1][j];
          }
        }
      }
    }
    return grid.back().back();
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int>> grid{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};

  cout << s.minPathSum(grid) << endl;

  return 0;
}

#endif
