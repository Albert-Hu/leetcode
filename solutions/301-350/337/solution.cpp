#ifdef LOCAL_TEST
#include "solution.h"
#else

class Solution {
public:
  int search(TreeNode *root, int &left, int &right);
  int rob(TreeNode *root);
};

#endif

int Solution::search(TreeNode *root, int &left, int &right) {
  if (root) {
    int left_left = 0, left_right = 0;
    int right_left = 0, right_right = 0;
    left = search(root->left, left_left, left_right);
    right = search(root->right, right_left, right_right);
    return max(root->val + left_left + left_right + right_left + right_right,
               left + right);
  }
  return 0;
}

int Solution::rob(TreeNode *root) {
  int left = 0, right = 0;
  return search(root, left, right);
}
