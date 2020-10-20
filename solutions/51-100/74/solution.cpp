#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    if (matrix.front().empty()) return false;

    int m = matrix.front().size() - 1;
    int r1 = 0, r2 = matrix.size() - 1;

    while (r1 < r2) {
      int mid = r1 + (r2 - r1) / 2;
      if (target >= matrix[r1][0] && target <= matrix[mid][m]) {
        r2 = mid;
      } else {
        r1 = mid + 1;
      }
    }

    int row = r1;
    r1 = 0, r2 = m;
    while (r1 < r2) {
      int mid = r1 + (r2 - r1) / 2;
      if (target >= matrix[row][r1] && target <= matrix[row][mid]) {
        r2 = mid;
      } else {
        r1 = mid + 1;
      }
    }

    return (matrix[row][r1] == target);
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int>> matrix;
  vector<int> line;

  line.push_back(1);
  line.push_back(3);
  line.push_back(5);
  line.push_back(7);
  matrix.push_back(line);

  line.clear();
  line.push_back(10);
  line.push_back(11);
  line.push_back(16);
  line.push_back(20);
  matrix.push_back(line);

  line.clear();
  line.push_back(23);
  line.push_back(30);
  line.push_back(34);
  line.push_back(50);
  matrix.push_back(line);

  cout << (s.searchMatrix(matrix, 3) ? "true" : "false") << endl;
  cout << (s.searchMatrix(matrix, 13) ? "true" : "false") << endl;

  return 0;
}

#endif
