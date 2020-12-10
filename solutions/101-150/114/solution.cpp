#ifdef LOCAL_TEST
#include "solution.h"
#else

typedef struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
} TreeNode;

class Solution {
public:
  void flatten(TreeNode* root);
};

#endif

void Solution::flatten(TreeNode* root) {
}
