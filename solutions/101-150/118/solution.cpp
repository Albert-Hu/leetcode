#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int> > generate(int numRows) {
    if (numRows == 0) return vector<vector<int> >();
    if (numRows == 1) return vector<vector<int> >{{1}};
    if (numRows == 2) return vector<vector<int> >{{1}, {1, 1}};

    vector<vector<int> > triangle;

    triangle.push_back(vector<int>{1});
    triangle.push_back(vector<int>{1, 1});

    for (int row = 2; row < numRows; row++) {
      triangle.push_back(vector<int>{1});
      for (int column = 1; column < triangle[row - 1].size(); column++) {
        triangle[row].push_back(triangle[row - 1][column] + triangle[row - 1][column - 1]);
      }
      triangle[row].push_back(1);
    }

    return triangle;
  }
};

#ifdef LOCAL_TEST

void dump(vector<vector<int> > triangle) {
  cout << "[" << endl;
  for (int i = 0; i < triangle.size(); i++) {
    cout << "  [";
    for (int j = 0; j < triangle[i].size(); j++) {
      if (j > 0) cout << ", ";
      cout << triangle[i][j];
    }
    cout << "]" << endl;
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;

  dump(s.generate(2));
  dump(s.generate(5));

  return 0;
}

#endif
