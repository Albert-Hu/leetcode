#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int minimum = INT32_MAX;

    for (int i = 1; i < triangle.size(); i++) {
      triangle[i][0] += triangle[i - 1][0];
      triangle[i][triangle[i].size() - 1] +=
          triangle[i - 1][triangle[i - 1].size() - 1];
      for (int j = 1; j < triangle[i].size() - 1; j++) {
        triangle[i][j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
      }
    }

    for (auto n : triangle.back()) {
      minimum = min(minimum, n);
    }

    return minimum;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

  cout << s.minimumTotal(triangle) << endl;

  return 0;
}

#endif
