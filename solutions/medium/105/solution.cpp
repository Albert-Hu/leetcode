#include <iostream>
#include <functional>
#include <vector>
#include <map>

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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int, int> inorder_indices;
    for (int i = 0; i < inorder.size(); ++i) {
      inorder_indices[inorder[i]] = i;
    }
    function<TreeNode*(int,int,int,int)> build = [&](int ps, int pe, int is, int ie) {
      if (ps > pe) return (TreeNode*)nullptr;
      TreeNode *root = new TreeNode(preorder[ps]);
      int im = inorder_indices[preorder[ps]];
      int pm = ps + (im - is);
      root->left = build(ps + 1, pm, is, im);
      root->right = build(pm + 1, pe, im + 1, ie);
      return root;
    };
    return build(0, preorder.size() - 1, 0, inorder.size() - 1);
  }
};

#ifdef LOCAL_TEST

void dump(vector<int> &array) {
  cout << "[";
  for (int i = 0; i < array.size(); ++i) {
    if (i > 0) cout << ", ";
    cout << array[i];
  }
  cout << "]" << endl;
}

void preorder_dump(TreeNode *root, vector<int> &array) {
  if (root != nullptr) {
    array.push_back(root->val);
    preorder_dump(root->left, array);
    preorder_dump(root->right, array);
  }
}

void inorder_dump(TreeNode *root, vector<int> &array) {
  if (root != nullptr) {
    inorder_dump(root->left, array);
    array.push_back(root->val);
    inorder_dump(root->right, array);
  }
}

int main(int argc, char *argv[]) {
  Solution *s;
  TreeNode *root = nullptr;
  vector<int> preorder, inorder;

  preorder.push_back(3);
  preorder.push_back(9);
  preorder.push_back(20);
  preorder.push_back(15);
  preorder.push_back(7);

  inorder.push_back(9);
  inorder.push_back(3);
  inorder.push_back(15);
  inorder.push_back(20);
  inorder.push_back(7);

  s = new Solution;
  root = s->buildTree(preorder, inorder);

  preorder.clear();
  preorder_dump(root, preorder);
  dump(preorder);
  inorder.clear();
  inorder_dump(root, inorder);
  dump(inorder);

  return 0;
}

#endif
