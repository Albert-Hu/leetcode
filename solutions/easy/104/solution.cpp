#include <iostream>
#include <limits>

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
  int maxDepth(TreeNode* root) {
    if (root == nullptr)
      return 0;
    if (root->left == nullptr && root->right == nullptr)
      return 1;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  TreeNode *root = nullptr;

  root = new TreeNode(
    3,
    new TreeNode(9),
    new TreeNode(
      20,
      new TreeNode(15),
      new TreeNode(7)
    )
  );

  cout << s.maxDepth(root) << endl;

  return 0;
}

#endif
