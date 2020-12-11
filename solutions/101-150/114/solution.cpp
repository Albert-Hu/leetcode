#ifdef LOCAL_TEST
#include "solution.h"
#else

class Solution {
public:
  TreeNode* search(TreeNode* root);
  void flatten(TreeNode* root);
};

#endif

TreeNode* Solution::search(TreeNode* root) {
  TreeNode *leftTail, *rightTail, *tail = root;

  if (root) {
    leftTail = search(root->left);
    rightTail = search(root->right);

    if (leftTail) {
      leftTail->right = root->right;
      root->right = root->left;
      root->left = nullptr;
      tail = leftTail;
    }

    if (rightTail) {
      tail = rightTail;
    }
  }

  return tail;
}

void Solution::flatten(TreeNode* root) {
  search(root);
}
