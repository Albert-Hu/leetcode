#include <iostream>
#include <vector>

using namespace std;

#define DEAD      (0)
#define LIVE      (1)
#define DEAD_NEXT (2)
#define LIVE_NEXT (3)

class Solution {
public:
  void gameOfLife(vector<vector<int> >& board) {
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        int count = countAliveNeighbors(board, i, j);
        if (board[i][j] == 0) {
          if (count == 3) board[i][j] = LIVE_NEXT;
        } else {
          if (count < 2 || count > 3) board[i][j] = DEAD_NEXT;
        }
      }
    }

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (board[i][j] == DEAD_NEXT) {
          board[i][j] = 0;
        } else if (board[i][j] == LIVE_NEXT) {
          board[i][j] = 1;
        }
      }
    }
  }

  int countAliveNeighbors(vector<vector<int> >& board, int i, int j) {
    int count = 0;

    if (isAlive(board, i - 1, j)) count++;
    if (isAlive(board, i - 1, j - 1)) count++;
    if (isAlive(board, i - 1, j + 1)) count++;
    if (isAlive(board, i + 1, j)) count++;
    if (isAlive(board, i + 1, j - 1)) count++;
    if (isAlive(board, i + 1, j + 1)) count++;
    if (isAlive(board, i, j - 1)) count++;
    if (isAlive(board, i, j + 1)) count++;

    return count;
  }

  bool isAlive(vector<vector<int> >& board, int i, int j) {
    if (i < 0 || i >= board.size())
      return false;
    if (j < 0 || j >= board[i].size())
      return false;
    return (board[i][j] == LIVE || board[i][j] == DEAD_NEXT);
  }
};

#ifdef LOCAL_TEST

void dump(vector<vector<int> > &board) {
  cout << "[" << endl;
  for (int i = 0; i < board.size(); i++) {
    cout << "  [";
    for (int j = 0; j < board[i].size(); j++) {
      if (j > 0) cout << ", ";
      cout << board[i][j];
    }
    if (i < (board.size() - 1)) cout << "]," << endl;
    else cout << "]" << endl;
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int> > board;

  board.push_back(vector<int>{0,1,0});
  board.push_back(vector<int>{0,0,1});
  board.push_back(vector<int>{1,1,1});
  board.push_back(vector<int>{0,0,0});
  s.gameOfLife(board);
  dump(board);

  return 0;
}

#endif
