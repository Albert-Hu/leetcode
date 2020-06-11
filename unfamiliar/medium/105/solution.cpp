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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return nullptr;
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
    preorder_dump(root->left, array);
    array.push_back(root->val);
    preorder_dump(root->right, array);
  }
}

int main(int argc, char *argv[]) {
  Solution s;
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

  root = s.buildTree(preorder, inorder);

  preorder.clear();
  preorder_dump(root, preorder);
  dump(preorder);
  inorder.clear();
  preorder_dump(root, inorder);
  dump(inorder);

  return 0;
}

#endif
