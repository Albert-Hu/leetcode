#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) {
      return false;
    }

    if (matrix.front().empty()) {
      return false;
    }

    int m = matrix.size();
    int column = matrix.front().size() - 1;
    int row = 0;

    while (column > -1 && row < m) {
      if (matrix[row][column] == target) {
        return true;
      }

      if (matrix[row][column] < target) {
        row++;
      } else {
        column--;
      }
    }

    return false;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int>> matrix;
  vector<int> line;

  line.push_back(1);
  line.push_back(4);
  line.push_back(7);
  line.push_back(11);
  line.push_back(15);
  matrix.push_back(line);

  line.clear();
  line.push_back(2);
  line.push_back(5);
  line.push_back(8);
  line.push_back(12);
  line.push_back(19);
  matrix.push_back(line);

  line.clear();
  line.push_back(3);
  line.push_back(6);
  line.push_back(9);
  line.push_back(16);
  line.push_back(22);
  matrix.push_back(line);

  line.clear();
  line.push_back(10);
  line.push_back(13);
  line.push_back(14);
  line.push_back(17);
  line.push_back(24);
  matrix.push_back(line);

  line.clear();
  line.push_back(18);
  line.push_back(21);
  line.push_back(23);
  line.push_back(26);
  line.push_back(30);
  matrix.push_back(line);

  cout << (s.searchMatrix(matrix, 5) ? "true" : "false") << endl;
  cout << (s.searchMatrix(matrix, 20) ? "true" : "false") << endl;

  line.clear();
  line.push_back(-1);
  line.push_back(3);
  matrix.clear();
  matrix.push_back(line);
  cout << (s.searchMatrix(matrix, -1) ? "true" : "false") << endl;

  line.clear();
  line.push_back(1);
  line.push_back(1);
  matrix.clear();
  matrix.push_back(line);
  cout << (s.searchMatrix(matrix, 2) ? "true" : "false") << endl;

  return 0;
}

#endif
