#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    vector<vector<bool>> visited;

    for (int i = 0; i < board.size(); ++i) {
      vector<bool> row(board[i].size(), false);
      visited.push_back(row);
    }

    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board[i].size(); ++j) {
        if (board[i][j] == word[0]) {
          if (search(board, visited, i, j, word, 0)) {
            return true;
          }
        }
      }
    }
    return false;
  }

private:
  bool search(vector<vector<char>> &board, vector<vector<bool>> &visited,
              int row, int column, string &word, int pos) {
    if (row < 0 || row >= board.size()) {
      return false;
    }
    if (column < 0 || column >= board[row].size()) {
      return false;
    }
    if (word[pos] == board[row][column] && !visited[row][column]) {
      if (pos == (word.size() - 1)) {
        return true;
      }
      visited[row][column] = true;
      if (search(board, visited, row - 1, column, word, pos + 1)) {
        return true;
      }
      if (search(board, visited, row + 1, column, word, pos + 1)) {
        return true;
      }
      if (search(board, visited, row, column - 1, word, pos + 1)) {
        return true;
      }
      if (search(board, visited, row, column + 1, word, pos + 1)) {
        return true;
      }
      visited[row][column] = false;
    }
    return false;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<char>> board;
  vector<char> row;

  row.push_back('A');
  row.push_back('B');
  row.push_back('C');
  row.push_back('E');
  board.push_back(row);

  row.clear();
  row.push_back('S');
  row.push_back('F');
  row.push_back('C');
  row.push_back('S');
  board.push_back(row);

  row.clear();
  row.push_back('A');
  row.push_back('D');
  row.push_back('E');
  row.push_back('E');
  board.push_back(row);

  cout << (s.exist(board, "ABCCED") ? "true" : "false") << endl;
  cout << (s.exist(board, "SEE") ? "true" : "false") << endl;
  cout << (s.exist(board, "ABCB") ? "true" : "false") << endl;

  return 0;
}

#endif
