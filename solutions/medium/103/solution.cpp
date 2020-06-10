#include <iostream>
#include <vector>
#include <map>

using namespace std;

#ifdef LOCAL_TEST

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif

class Solution {
public:
  vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > result;
    dfs(root, 0, true);
    for (auto it : levels) {
      result.push_back(it.second);
    }
    return result;
  }
private:
  void dfs(TreeNode *root, int n, bool left2right) {
    if (root != nullptr) {
      if (left2right) {
        levels[n].push_back(root->val);
      } else {
        levels[n].insert(levels[n].begin(), root->val);
      }
      dfs(root->left, n + 1, !left2right);
      dfs(root->right, n + 1, !left2right);
    }
  }

private:
  map<int, vector<int> > levels;
};

#ifdef LOCAL_TEST

void dump(vector<vector<int> > result) {
  cout << "[" << endl;
  for (int i = 0; i < result.size(); ++i) {
    cout << "  [";
    for (int j = 0; j < result[i].size(); ++j) {
      if (j > 0) cout << ", ";
      cout << result[i][j];
    }
    cout << "]" << endl;
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution *s;
  TreeNode *root;

  root = new TreeNode(
    3,
    new TreeNode(9),
    new TreeNode(
      20,
      new TreeNode(15),
      new TreeNode(7)
    )
  );
  s = new Solution;
  dump(s->zigzagLevelOrder(root));

  return 0;
}

#endif
