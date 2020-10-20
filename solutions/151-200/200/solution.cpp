#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    int count = 0;
    for (int y = 0; y < grid.size(); y++) {
      for (int x = 0; x < grid[y].size(); x++) {
        if (grid[y][x] == '1') {
          count++;
          explore(grid, x, y);
        }
      }
    }
    return count;
  }

  void explore(vector<vector<char>>& grid, int x, int y) {
    if (y < 0 || y >= grid.size()) return;
    if (x < 0 || x >= grid[y].size()) return;
    if (grid[y][x] == '0') return;

    grid[y][x] = '0';
    explore(grid, x - 1, y);
    explore(grid, x + 1, y);
    explore(grid, x, y - 1);
    explore(grid, x, y + 1);
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<char> > grid;

  grid.push_back(vector<char>{{'1','1','1','1','0'}});
  grid.push_back(vector<char>{{'1','1','0','1','0'}});
  grid.push_back(vector<char>{{'1','1','0','0','0'}});
  grid.push_back(vector<char>{{'0','0','0','0','0'}});
  cout << s.numIslands(grid) << endl;

  grid.clear();
  grid.push_back(vector<char>{{'1','1','0','0','0'}});
  grid.push_back(vector<char>{{'1','1','0','0','0'}});
  grid.push_back(vector<char>{{'0','0','1','0','0'}});
  grid.push_back(vector<char>{{'0','0','0','1','1'}});
  cout << s.numIslands(grid) << endl;

  return 0;
}

#endif
