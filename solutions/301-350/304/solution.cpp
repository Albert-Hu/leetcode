#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
  NumMatrix(vector<vector<int>>& matrix) {
    m_matrix = matrix;
    for (int i = 0; i < m_matrix.size(); i++) {
      for (int j = 1; j < m_matrix[i].size(); j++) {
        m_matrix[i][j] += m_matrix[i][j - 1];
      }
    }
  }
  
  int sumRegion(int row1, int col1, int row2, int col2) {
    int sum = 0;
    for (int i = row1; i <= row2; i++) {
      if (col1 > 0) {
        sum = sum + m_matrix[i][col2] - m_matrix[i][col1 - 1];
      } else {
        sum = sum + m_matrix[i][col2];
      }
    }
    return sum;
  }

  vector<vector<int>> m_matrix;
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  vector<vector<int>> matrix = {
    {3, 0, 1, 4, 2},
    {5, 6, 3, 2, 1},
    {1, 2, 0, 1, 5},
    {4, 1, 0, 1, 7},
    {1, 0, 3, 0, 5}
  };
  NumMatrix* obj = new NumMatrix(matrix);

  cout << obj->sumRegion(2, 1, 4, 3) << endl;
  cout << obj->sumRegion(1, 1, 2, 2) << endl;
  cout << obj->sumRegion(1, 2, 2, 4) << endl;

  return 0;
}

#endif
