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
    return recursive_inorder(root);
    //return loop_inorder(root);
  }
private:
  bool loop_inorder(TreeNode *root) {
    vector<TreeNode*> stack;
    TreeNode *last = nullptr;

    do {
      while (root != nullptr) {
        stack.push_back(root);
        root = root->left;
      }
      if (!stack.empty()) {
        root = stack.back();
        stack.pop_back();
        if (last != nullptr) {
          if (last->val >= root->val) {
            return false;
          }
        }
        last = root;
        if ((root = root->right) != nullptr) {
          stack.push_back(root);
          root = root->left;
        }
      }
    } while (!stack.empty());
    
    return true;
  }

  bool recursive_inorder(TreeNode *root) {
    vector<int> array;
    inorder(root, array);
    for (int i = 1; i < array.size(); ++i) {
      if (array[i] <= array[i - 1]) {
        return false;
      }
    }
    return true;
  }

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
