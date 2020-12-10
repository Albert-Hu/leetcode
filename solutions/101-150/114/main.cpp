#include <iomanip>
#include <iostream>
#include <vector>
#include <queue>

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

TreeNode* build_node(string value) {
  return (value == "null") ? nullptr : new TreeNode(stod(value));
}

bool get_tree(TreeNode **root) {
  size_t begin = 0, end;
  string line;
  vector<TreeNode*> array;

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

  cout << "array: ";
  for (auto node : array) {
    cout << (node ? to_string(node->val) : "null") << " ";
  }
  cout << endl;

  begin = 0;
  while (begin < array.size()) {
    size_t left = begin * 2 + 1;
    size_t right = left + 1;

    if (array[begin]) {
      if (right < array.size()) {
        array[begin]->right = array[right];

        cout << array[begin]->val << "->right: " << (array[right] ? to_string(array[right]->val) : "null") << endl;
      }

      if (left < array.size()) {
        array[begin]->left = array[left];

        cout << array[begin]->val << "->left: " << (array[left] ? to_string(array[left]->val) : "null") << endl;
      }
    }

    begin = (left < array.size()) ? (begin + 1) : array.size();
  }

  *root = array.front();

  return true;
}

void dump(TreeNode *root) {
  queue<TreeNode*> q;
  
  q.push(root);

  while (!q.empty()) {
    root = q.front();
    q.pop();
    if (root) {
      q.push(root->left);
      q.push(root->right);
      cout << root->val << " ";
    } else {
      cout << "null ";
    }
  }

  cout << endl;
}

int main(int argc, char *argv[]) {
  int test_case = 1;

  while (1) {
    TreeNode *input, *answer;

    if (!get_tree(&input)) break;
    if (!get_tree(&answer)) break;

    //dump(input);
    dump(answer);

    cout << "Test " << std::left << setw(3) << test_case++ << ": ";
    if (0) {
      cout << "[PASS]";
    } else {
      cout << "[FAIL]";
    }
    cout << endl;
  }

  return 0;
}
