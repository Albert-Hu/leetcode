#include <iostream>

using namespace std;

#ifdef LOCAL_TEST

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

#endif

class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    search(root, p, q);
    return node;
  }

private:
  int search(TreeNode* root, TreeNode* p, TreeNode* q) {
    int l = 0, r = 0, x = 0;
    if (root == nullptr) {
      return 0;
    }
    if (root->val == p->val || root->val == q->val) {
      x = 1;
    }
    l = search(root->left, p, q);
    if (l < 2) {
      r = search(root->right, p, q);
      if ((l == 1 && r == 1) || (x == 1 && (l == 1 || r == 1))) {
        node = root;
      }
    }
    return x + l + r;
  }

private:
  TreeNode *node;
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  TreeNode *root, *node;
  TreeNode *p, *q1, *q2;

  root = new TreeNode(
    3,
    (p = new TreeNode(
      5,
      new TreeNode(6),
      new TreeNode(
        2,
        new TreeNode(7),
        (q2 = new TreeNode(4))
      )
    )),
    (q1 = new TreeNode(
      1,
      new TreeNode(0),
      new TreeNode(8)
    ))
  );

  node = s.lowestCommonAncestor(root, p, q1);
  cout << node->val << endl;

  node = s.lowestCommonAncestor(root, p, q2);
  cout << node->val << endl;

  return 0;
}

#endif
