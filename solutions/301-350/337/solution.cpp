#ifdef LOCAL_TEST
#include "solution.h"
#else

class Solution {
public:
  int search(TreeNode* root);
  int rob(TreeNode* root);
};

#endif

int Solution::search(TreeNode* root) {
  if (!root)
    return 0;

  bool addRoot = true;
  int value = 0;
  int left = rob(root->left);
  int right = rob(root->right);

  if (root->left) {
    if (root->left->val > left) {
      value = root->left->val;
      addRoot = false;
    } else {
      value = left;
    }
  }

  if (root->right) {
    if (root->right->val > right) {
      value = value + root->right->val;
      addRoot = false;
    } else {
      value = value + right;
    }
  }

  if (addRoot) {
    root->val = root->val + value;
  } else {
    root->val = value;
  }

  return max((root->left ? root->left->val : 0), (root->right ? root->right->val : 0));
}

int Solution::rob(TreeNode* root) {
  if (!root)
    return 0;
  
  search(root);

  return root->val;
}