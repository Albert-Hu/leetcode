#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char> >& board) {
    bool found[3][9];
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        found[0][j] = false;
        found[1][j] = false;
        found[2][j] = false;
      }
      for (int j = 0; j < 9; ++j) {
        int x = ((i / 3) * 3) + j / 3;
        int y = ((i % 3) * 3) + (j % 3);
        if (board[x][y] != '.') {
          int index = (board[x][y] - '0') - 1;
          if (found[0][index]) return false;
          found[0][index] = true;
        }
        if (board[i][j] != '.') {
          int index = (board[i][j] - '0') - 1;
          if (found[1][index]) return false;
          found[1][index] = true;
        }
        if (board[j][i] != '.') {
          int index = (board[j][i] - '0') - 1;
          if (found[2][index]) return false;
          found[2][index] = true;
        }
      }
    }
    return true;
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
