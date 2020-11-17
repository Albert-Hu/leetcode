#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> merged;

    if (intervals.size() == 0) {
      return merged;
    }

    sort(intervals.begin(), intervals.end(),
         [&](vector<int> &a, vector<int> &b) { return a[0] < b[0]; });

    merged.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
      int prev = merged.size() - 1;
      if (merged[prev][1] >= intervals[i][0]) {
        if (merged[prev][1] < intervals[i][1]) {
          merged[prev][1] = intervals[i][1];
        }
      } else {
        merged.push_back(intervals[i]);
      }
    }

    return merged;
  }
};

#ifdef LOCAL_TEST

void dump(vector<vector<int>> intervals) {
  cout << "[" << endl;
  for (int i = 0; i < intervals.size(); ++i) {
    cout << "[";
    for (int j = 0; j < intervals[i].size(); ++j) {
      if (j > 0)
        cout << ", ";
      cout << intervals[i][j];
    }
    cout << "]" << endl;
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<vector<int>> intervals;
  vector<int> line;

  line.push_back(1);
  line.push_back(3);
  intervals.push_back(line);

  line.clear();
  line.push_back(2);
  line.push_back(6);
  intervals.push_back(line);

  line.clear();
  line.push_back(8);
  line.push_back(10);
  intervals.push_back(line);

  line.clear();
  line.push_back(15);
  line.push_back(18);
  intervals.push_back(line);

  dump(s.merge(intervals));

  return 0;
}

#endif
