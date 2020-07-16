#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int kthSmallest(vector<vector<int> >& matrix, int k) {
    int left = matrix[0][0], right = matrix.back().back();

    while (left < right) {
      int count = 0;
      int middle = left + (right - left) / 2;
      for (int i = 0; i < matrix.size(); i++) {
        count += upper_bound(matrix[i].begin(), matrix[i].end(), middle) - matrix[i].begin();
      }
      if (count < k) left = middle + 1;
      else right = middle;
    }

    return left;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int> > matrix{
    vector<int> {1, 5, 9},
    vector<int> {10, 11, 13},
    vector<int> {12, 13, 15}
  };

  cout << s.kthSmallest(matrix, 8) << endl;

  return 0;
}

#endif
