#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> subsets(vector<int> &nums) {
    int n;
    vector<int> set;

    n = nums.size();
    result.push_back(set);
    for (int i = 1; i <= nums.size(); ++i) {
      generate(nums, 0, i, set);
    }
    return result;
  }

private:
  void generate(vector<int> &nums, int pos, int n, vector<int> &set) {
    if (set.size() == n) {
      result.push_back(set);
    } else {
      for (int i = pos; i < nums.size(); ++i) {
        set.push_back(nums[i]);
        generate(nums, i + 1, n, set);
        set.pop_back();
      }
    }
  }

private:
  vector<vector<int>> result;
};

#ifdef LOCAL_TEST

void dump(vector<vector<int>> result) {
  cout << "[" << endl;
  for (int i = 0; i < result.size(); ++i) {
    cout << "  [";
    for (int j = 0; j < result[i].size(); ++j) {
      if (j > 0)
        cout << ", ";
      cout << result[i][j];
    }
    cout << "]" << endl;
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums;

  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  dump(s.subsets(nums));

  return 0;
}

#endif
