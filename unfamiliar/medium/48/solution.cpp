#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int> >& matrix) {
    // solve it again
  }
};

#ifdef LOCAL_TEST

void dump(vector<vector<int> > &matrix) {
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

  s.rotate(matrix);
  dump(matrix);

  return 0;
}

#endif
