#include <iostream>
#include <vector>
#include <stack>

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
  vector<TreeNode*> generateTrees(int n) {
    if (n == 0) {
      vector<TreeNode*> empty;
      return empty;
    }
    return generate(1, n);
  }
  vector<TreeNode*> generate(int start, int end) {
    if (start > end) return { nullptr };

    vector<TreeNode*> nodes;
    for (int i = start; i <= end; i++) {
      auto left = generate(start, i - 1);
      auto right = generate(i + 1, end);
      for (auto l : left) {
        for (auto r : right) {
          nodes.push_back(new TreeNode(i, l, r));
        }
      }
    }

    return nodes;
  }
};

#ifdef LOCAL_TEST

void dump(TreeNode *root) {
  if (root != nullptr) {
    cout << root->val << ", ";
    dump(root->left);
    dump(root->right);
  } else {
    cout << "null, ";
  }
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<TreeNode*> answer;

  answer = s.generateTrees(3);
  for (auto node : answer) {
    dump(node);
    cout << endl;
  }

  return 0;
}

#endif
