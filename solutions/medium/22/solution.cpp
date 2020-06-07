#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> generateParenthesis(int n) {
    ans.clear();
    generate(n, 0, 0, "");
    return ans;
  }

private:
  void generate(int n, int l, int r, string s) {
    if (l == r && r == n) {
      ans.push_back(s);
    } else {
      if (l < n) {
        generate(n, l + 1, r, s + '(');
      }
      if (l > r) {
        generate(n, l, r + 1, s + ')');
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
    if (i > 0) cout << ", ";
    cout << ans[i];
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;

  dump(s.generateParenthesis(3));

  return 0;
}

#endif
