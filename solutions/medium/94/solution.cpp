#include <iostream>
#include <vector>
#include <stack>

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
  vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> s;
    vector<int> visited;

    do {
      while (root != nullptr) {
        s.push(root);
        root = root->left;
      }
      if (!s.empty()) {
        root = s.top();
        s.pop();
        visited.push_back(root->val);
        root = root->right;
        if (root != nullptr) {
          s.push(root);
          root = root->left;
        }
      }
    } while (!s.empty());

    return visited;
  }
};

#ifdef LOCAL_TEST

void dump(vector<int> result) {
  cout << "[";
  for (int i = 0; i < result.size(); ++i) {
    if (i > 0) cout << ", ";
    cout << result[i];
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution *s;
  TreeNode *root;

  s = new Solution();
  root = new TreeNode(
    1,
    nullptr,
    new TreeNode(
      2,
      new TreeNode(3),
      nullptr
    )
  );
  dump(s->inorderTraversal(root));

  return 0;
}

#endif
