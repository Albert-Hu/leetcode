#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int r = 0, c = 1;
    int i = 0, j = 0;
    vector<int> output;

    if (matrix.size() == 0) {
      return output;
    }

    int x = 0, y = 1;
    int m = matrix.size() - 1;
    int n = matrix[0].size() - 1;
    int count = (m + 1) * (n + 1);
    while (count-- > 0) {
      output.push_back(matrix[i][j]);
      if (r == 0 && c == 1) { // move from left to right
        if (j == n) {
          r = 1;
          c = 0;
        }
      } else if (r == 1 && c == 0) { // move from top to bottom
        if (i == m) {
          r = 0;
          c = -1;
        }
      } else if (r == 0 && c == -1) { // move from right to left
        if (j == x) {
          r = -1;
          c = 0;
        }
      } else { // move from bottom to top
        if (i == y) {
          r = 0;
          c = 1;
          y++;
          x++;
          m--;
          n--;
        }
      }
      i += r;
      j += c;
    }

    return output;
  }
};

#ifdef LOCAL_TEST

void dump(vector<int> output) {
  cout << "[";
  for (int i = 0; i < output.size(); ++i) {
    if (i > 0) cout << ", ";
    cout << output[i];
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int> > matrix;
  vector<int> row;

  row.push_back(1);
  row.push_back(2);
  row.push_back(3);
  matrix.push_back(row);

  row.clear();
  row.push_back(4);
  row.push_back(5);
  row.push_back(6);
  matrix.push_back(row);

  row.clear();
  row.push_back(7);
  row.push_back(8);
  row.push_back(9);
  matrix.push_back(row);

  dump(s.spiralOrder(matrix));

  matrix.clear();
  row.clear();
  row.push_back(1);
  row.push_back(2);
  row.push_back(3);
  row.push_back(4);
  matrix.push_back(row);

  row.clear();
  row.push_back(5);
  row.push_back(6);
  row.push_back(7);
  row.push_back(8);
  matrix.push_back(row);

  row.clear();
  row.push_back(9);
  row.push_back(10);
  row.push_back(11);
  row.push_back(12);
  matrix.push_back(row);

  dump(s.spiralOrder(matrix));

  return 0;
}

#endif
