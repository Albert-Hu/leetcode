#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
  void solve(vector<vector<char> >& board) {
    vector<vector<bool> > x;
    function<void(int,int)> search = [&](int row, int column) {
      if (row < 0 || row >= board.size()) return;
      if (column < 0 || column >= board[row].size()) return;
      if (board[row][column] == 'X' || !x[row][column]) return;
      
      x[row][column] = false;
      search(row - 1, column);
      search(row + 1, column);
      search(row, column - 1);
      search(row, column + 1);
    };
    
    if (board.size() == 0) return;
    if (board[0].size() == 0) return;

    for (int i = 0; i < board.size(); ++i) {
      vector<bool> row(board[i].size(), true);
      x.push_back(row);
    }

    for (int i = 0; i < board.size(); ++i) {
      if (i == 0 || i == (board.size() - 1)) {
        for (int j = 0; j < board[i].size(); ++j) {
          search(i, j);
        }
      } else {
        search(i, 0);
        search(i, board[i].size() - 1);
      }
    }

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (x[i][j] && board[i][j] == 'O') {
          board[i][j] = 'X';
        }
      }
    }
  }
};

#ifdef LOCAL_TEST

void dump(vector<vector<char> >& board) {
  cout << "[" << endl;
  for (int i = 0; i < board.size(); ++i) {
    cout << "  [";
    for (int j = 0; j < board[i].size(); ++j) {
      if (j > 0) cout << ", ";
      cout << board[i][j];
    }
    cout << "]" << endl;
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<char> > board;
  vector<char> row;

  row.push_back('X');
  row.push_back('X');
  row.push_back('X');
  row.push_back('X');
  board.push_back(row);

  row.clear();
  row.push_back('X');
  row.push_back('O');
  row.push_back('O');
  row.push_back('X');
  board.push_back(row);

  row.clear();
  row.push_back('X');
  row.push_back('X');
  row.push_back('O');
  row.push_back('X');
  board.push_back(row);

  row.clear();
  row.push_back('X');
  row.push_back('O');
  row.push_back('X');
  row.push_back('X');
  board.push_back(row);

  s.solve(board);
  dump(board);

  return 0;
}

#endif
