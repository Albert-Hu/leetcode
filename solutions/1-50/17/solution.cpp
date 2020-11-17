#include <iostream>
#include <vector>

using namespace std;

char key_map[8][4] = {{'a', 'b', 'c', '\0'}, {'d', 'e', 'f', '\0'},
                      {'g', 'h', 'i', '\0'}, {'j', 'k', 'l', '\0'},
                      {'m', 'n', 'o', '\0'}, {'p', 'q', 'r', 's'},
                      {'t', 'u', 'v', '\0'}, {'w', 'x', 'y', 'z'}};

class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<int> nums;

    ans.clear();
    if (digits.size() > 0) {
      for (auto d : digits) {
        nums.push_back((d - '0') - 2);
      }
      combine(nums, 0, "");
    }

    return ans;
  }

private:
  void combine(vector<int> &nums, int pos, string s) {
    if (pos == (nums.size() - 1)) {
      for (int i = 0; i < 4 && key_map[nums[pos]][i] != '\0'; ++i) {
        ans.push_back(s + key_map[nums[pos]][i]);
      }
    } else {
      for (int i = 0; i < 4 && key_map[nums[pos]][i] != '\0'; ++i) {
        combine(nums, pos + 1, s + key_map[nums[pos]][i]);
      }
    }
  }

private:
  vector<string> ans;
};

#ifdef LOCAL_TEST

void dump(vector<string> ans) {
  cout << "[";
  for (int i = 0; i < ans.size(); ++i) {
    if (i > 0)
      cout << ", ";
    cout << ans[i];
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  string digits;

  digits = "23";
  dump(s.letterCombinations(digits));

  return 0;
}

#endif
