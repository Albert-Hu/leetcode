#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int> >& matrix) {
    bool r = false, c = false;
    if (matrix.size() == 0) {
      return;
    }
    if (matrix[0].size() == 0) {
      return;
    }
    for (int i = 0; i < matrix.size() && !r; ++i) {
      r = (matrix[i][0] == 0);
    }
    for (int i = 0; i < matrix[0].size() && !c; ++i) {
      c = (matrix[0][i] == 0);
    }
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[i].size(); ++j) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }
    for (int i = 1; i < matrix.size(); ++i) {
      for (int j = 1; j < matrix[i].size(); ++j) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }
    if (r) {
      for (int i = 0; i < matrix.size(); ++i) {
        matrix[i][0] = 0;
      }
    }
    if (c) {
      for (int i = 0; i < matrix[0].size(); ++i) {
        matrix[0][i] = 0;
      }
    }
  }
};

#ifdef LOCAL_TEST

void dump(vector<vector<int> >& matrix) {
  cout << "[" << endl;
  for (int i = 0; i < matrix.size(); ++i) {
    cout << "  [";
    for (int j = 0; j < matrix[i].size(); ++j) {
      if (j > 0) cout << ", ";
      cout << matrix[i][j];
    }
    cout << "]" << endl;
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int> > matrix;
  vector<int> row;

  row.push_back(1);
  row.push_back(1);
  row.push_back(1);
  matrix.push_back(row);

  row.clear();
  row.push_back(1);
  row.push_back(0);
  row.push_back(1);
  matrix.push_back(row);

  row.clear();
  row.push_back(1);
  row.push_back(1);
  row.push_back(1);
  matrix.push_back(row);

  s.setZeroes(matrix);
  dump(matrix);

  matrix.clear();

  row.clear();
  row.push_back(0);
  row.push_back(1);
  row.push_back(2);
  row.push_back(0);
  matrix.push_back(row);

  row.clear();
  row.push_back(3);
  row.push_back(4);
  row.push_back(5);
  row.push_back(2);
  matrix.push_back(row);

  row.clear();
  row.push_back(1);
  row.push_back(3);
  row.push_back(1);
  row.push_back(5);
  matrix.push_back(row);

  s.setZeroes(matrix);
  dump(matrix);

  return 0;
}

#endif
