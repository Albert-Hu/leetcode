#include <iomanip>
#include <iostream>
#include <queue>
#include <vector>

#include "solution.h"

using namespace std;

string remove_space(string line) {
  string newLine;

  for (auto c : line) {
    if (c != ' ')
      newLine.push_back(c);
  }

  return newLine;
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

bool get_answer(int &answer) {
  string line;

  if (!getline(cin, line))
    return false;

  answer = stod(line);

  return true;
}

int main(int argc, char *argv[]) {
  int test_case = 1;

  while (1) {
    int answer;
    TreeNode *root;
    Solution s;

    if (!get_tree(&root))
      break;
    if (!get_answer(answer))
      break;

    cout << "Test " << std::left << setw(3) << test_case++ << ": ";
    if (s.rob(root) == answer) {
      cout << "[PASS]";
    } else {
      cout << "[FAIL]";
    }
    cout << endl;
  }

  return 0;
}
