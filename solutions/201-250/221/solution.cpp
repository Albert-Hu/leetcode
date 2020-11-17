#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int area(vector<vector<char>> &matrix, int row, int column, int n) {
    if ((row + n) > matrix.size())
      return 0;

    if ((column + n) > matrix.front().size())
      return 0;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[row + i][column + j] != '1')
          return 0;
      }
    }

    return n * n;
  }

  int maximalSquare(vector<vector<char>> &matrix) {
    int maximum = 0;

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        if (matrix[i][j] == '1') {
          for (int n = 1, m = 1; n <= matrix[i].size() && m > 0; n++) {
            m = area(matrix, i, j, n);
            maximum = max(maximum, m);
          }
        }
      }
    }

    return maximum;
    ;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
#if 1
  vector<vector<char>> matrix{
      {'1', '0', '1', '0', '0'},
      {'1', '0', '1', '1', '1'},
      {'1', '1', '1', '1', '1'},
      {'1', '0', '0', '1', '0'},
  };
#else
  vector<vector<char>> matrix{{'1'}};
#endif
  cout << s.maximalSquare(matrix) << endl;

  return 0;
}

#endif
