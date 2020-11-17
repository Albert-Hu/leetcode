#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#ifdef LOCAL_TEST
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
#endif

class Solution {
public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    if (nums.size() == 0)
      return nullptr;

    int middle = nums.size() / 2;
    TreeNode *root = new TreeNode(nums[middle]);

    if ((middle - 1) > -1) {
      vector<int> left(nums.begin(), nums.begin() + middle);
      root->left = sortedArrayToBST(left);
    }

    if ((middle + 1) < nums.size()) {
      vector<int> right(nums.begin() + (middle + 1),
                        nums.begin() + nums.size());
      root->right = sortedArrayToBST(right);
    }

    return root;
  }
};

#ifdef LOCAL_TEST

void dump(TreeNode *root) {
  bool begin = true;
  queue<TreeNode *> q;

  cout << "[";
  q.push(root);
  while (!q.empty()) {
    root = q.front();
    q.pop();

    if (begin)
      begin = !begin;
    else
      cout << ", ";

    if (root == nullptr) {
      cout << "null";
    } else {
      cout << root->val;
      if (root->left != nullptr || root->right != nullptr) {
        q.push(root->left);
        q.push(root->right);
      }
    }
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums{-10, -3, 0, 5, 9};

  dump(s.sortedArrayToBST(nums));

  return 0;
}

#endif
