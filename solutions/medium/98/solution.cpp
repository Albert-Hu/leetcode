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
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#endif

class Solution {
public:
  bool isValidBST(TreeNode *root) {
    vector<int> array;
    inorder(root, array);
    for (int i = 1; i < array.size(); ++i) {
      if (array[i] <= array[i - 1]) {
        return false;
      }
    }
    return true;
  }
private:
  void inorder(TreeNode *root, vector<int> &array) {
    if (root != nullptr) {
      inorder(root->left, array);
      array.push_back(root->val);
      inorder(root->right, array);
    }
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  TreeNode *root = nullptr;

  root = new TreeNode(
    2,
    new TreeNode(1),
    new TreeNode(3)
  );
  cout << (s.isValidBST(root) ? "true" : "false") << endl;

  root = new TreeNode(
    5,
    new TreeNode(1),
    new TreeNode(
      4,
      new TreeNode(3),
      new TreeNode(6)
    )
  );
  cout << (s.isValidBST(root) ? "true" : "false") << endl;

  return 0;
}

#endif
