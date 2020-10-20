#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int uniquePaths(int m, int n) {
    vector<int> path(n, 0);
    path[0] = 1;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j > 0) {
          path[j] += path[j - 1];
        }
      }
    }
    return path.back();
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.uniquePaths(3, 2) << endl;
  cout << s.uniquePaths(7, 3) << endl;

  return 0;
}

#endif
