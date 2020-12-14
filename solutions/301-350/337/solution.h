#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <iostream>
#include <algorithm>

using namespace std;

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
  int search(TreeNode* root);
  int rob(TreeNode* root);
};

#endif /* _SOLUTION_H_ */
