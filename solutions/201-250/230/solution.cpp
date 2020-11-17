#include <iostream>
using namespace std;

#ifdef LOCAL_TEST

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

#endif

class Solution {
public:
  Solution() : count(0), answer(0) {}

  int kthSmallest(TreeNode *root, int k) {
    dfs(root, k);
    return answer;
  }

private:
  void dfs(TreeNode *root, int k) {
    if (root != nullptr && count != k) {
      dfs(root->left, k);
      if (++count == k) {
        answer = root->val;
      } else {
        dfs(root->right, k);
      }
    }
  }

private:
  int count;
  int answer;
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution *s;
  TreeNode *root;

  s = new Solution();
  root = new TreeNode(3, new TreeNode(1, nullptr, new TreeNode(2)),
                      new TreeNode(4));
  cout << s->kthSmallest(root, 1) << endl;

  s = new Solution();
  root = new TreeNode(5,
                      new TreeNode(3, new TreeNode(2, new TreeNode(1), nullptr),
                                   new TreeNode(4)),
                      new TreeNode(6));
  cout << s->kthSmallest(root, 3) << endl;

  return 0;
}

#endif
