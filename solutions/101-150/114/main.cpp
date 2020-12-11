#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>

#include "solution.h"

using namespace std;

string remove_space(string str) {
  string new_str;

  for (auto c : str) {
    if (c != ' ')
      new_str.push_back(c);
  }

  return new_str;
}

TreeNode *build_node(string value) {
  return (value == "null") ? nullptr : new TreeNode(stod(value));
}

bool get_tree(TreeNode **root) {
  size_t begin = 0, end;
  string line;
  vector<TreeNode *> array;
  queue<TreeNode *> q;

  *root = nullptr;

  if (!getline(cin, line))
    return false;

  if (line.length() == 0)
    return true;

  line = remove_space(line);

  while ((end = line.find(',', begin)) != string::npos) {
    array.push_back(build_node(line.substr(begin, end - begin)));
    begin = end + 1;
  }
  array.push_back(build_node(line.substr(begin)));

  *root = array.front();
  q.push(*root);

  begin = 1;
  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();

    if (begin < array.size()) {
      node->left = array[begin++];
      if (node->left)
        q.push(node->left);
    }

    if (begin < array.size()) {
      node->right = array[begin++];
      if (node->right)
        q.push(node->right);
    }
  }

  return true;
}

void dump(TreeNode *root) {
  queue<TreeNode *> q;

  q.push(root);

  while (!q.empty()) {
    root = q.front();
    q.pop();
    if (root) {
      if (root->left != nullptr || root->right != nullptr) {
        q.push(root->left);
        q.push(root->right);
        cout << root->val << " ";
      }
    } else {
      cout << "null ";
    }
  }

  cout << endl;
}

bool verify(TreeNode *result, TreeNode *answer) {
  if (result == nullptr || answer == nullptr) {
    return (result == nullptr && answer == nullptr);
  }

  if (result->val != answer->val) {
    return false;
  }

  if (!verify(result->left, answer->left)) {
    return false;
  }

  return verify(result->right, answer->right);
}

int main(int argc, char *argv[]) {
  int test_case = 1;

  while (1) {
    Solution s;
    TreeNode *input, *answer;

    if (!get_tree(&input))
      break;
    if (!get_tree(&answer))
      break;

    s.flatten(input);

    cout << "Test " << std::left << setw(3) << test_case++ << ": ";
    if (verify(input, answer)) {
      cout << "[PASS]";
    } else {
      cout << "[FAIL]";
    }
    cout << endl;
  }

  return 0;
}
