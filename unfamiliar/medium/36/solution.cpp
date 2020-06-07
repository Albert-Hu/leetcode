#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char> >& board) {
    // solve it again!
    return false;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<char> > board;
  char example1[9][9] = {
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
  };
  char example2[9][9] = {
    {'8','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'}
  };

  for (int i = 0; i < 9; ++i) {
    vector<char> line;
    for (int j = 0; j < 9; ++j) {
      line.push_back(example1[i][j]);
    }
    board.push_back(line);
  }
  cout << (s.isValidSudoku(board) ? "true" : "false") << endl;

  board.clear();
  for (int i = 0; i < 9; ++i) {
    vector<char> line;
    for (int j = 0; j < 9; ++j) {
      line.push_back(example2[i][j]);
    }
    board.push_back(line);
  }
  cout << (s.isValidSudoku(board) ? "true" : "false") << endl;

  return 0;
}

#endif
