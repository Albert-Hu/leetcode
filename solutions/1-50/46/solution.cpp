#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    results.clear();
    if (nums.size() > 0) {
      vector<bool> used(nums.size(), false);
      vector<int> stack;
      backtrack(nums, used, stack);
    }
    return results;
  }

private:
  void backtrack(vector<int> &nums, vector<bool> &used, vector<int> &stack) {
    if (stack.size() == nums.size()) {
      results.push_back(stack);
    } else {
      for (int i = 0; i < nums.size(); ++i) {
        if (!used[i]) {
          used[i] = true;
          stack.push_back(nums[i]);
          backtrack(nums, used, stack);
          stack.pop_back();
          used[i] = false;
        }
      }
    }
  }

private:
  vector<vector<int>> results;
};

#ifdef LOCAL_TEST

void dump(vector<vector<int>> results) {
  cout << "[" << endl;
  for (int i = 0; i < results.size(); ++i) {
    cout << "  [";
    for (int j = 0; j < results[i].size(); ++j) {
      if (j > 0)
        cout << ", ";
      cout << results[i][j];
    }
    cout << "]" << endl;
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> integers;

  integers.push_back(1);
  integers.push_back(2);
  integers.push_back(3);
  dump(s.permute(integers));

  return 0;
}

#endif
