#include <iostream>
#include <vector>

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
  Solution() : sum(0) {}

  TreeNode *convertBST(TreeNode *root) {
    if (root != nullptr) {
      convertBST(root->right);
      root->val += sum;
      sum = root->val;
      convertBST(root->left);
    }
    return root;
  }

  int sum;
};

#ifdef LOCAL_TEST

void dump(TreeNode *root, int depth) {
  if (root != nullptr) {
    for (int i = 0; i < depth; i++) {
      cout << " ";
    }
    cout << root->val << endl;
    dump(root->left, depth + 1);
    dump(root->right, depth + 1);
  }
}

int main(int argc, char *argv[]) {
  Solution s;
  TreeNode *root = nullptr;

  root = s.convertBST(new TreeNode(5, new TreeNode(2), new TreeNode(13)));
  dump(root, 0);

  return 0;
}

#endif
