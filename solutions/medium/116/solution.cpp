#include <iostream>
#include <vector>
#include <functional>

using namespace std;

#ifdef LOCAL_TEST

class Node {
public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
    : val(_val), left(_left), right(_right), next(_next) {}
};

#endif

class Solution {
public:
  Node* connect(Node* root) {
    vector<Node*> nodes;
    function<Node*(Node*,int)> connect = [&](Node *current, int level) {
      if (current != nullptr) {
        if (level < nodes.size()) {
          nodes[level]->next = current;
          nodes[level] = current;
        } else {
          nodes.push_back(current);
        }
        connect(current->left, level + 1);
        connect(current->right, level + 1);
      }
      return current;
    };
    return connect(root, 0);
  }
};

#ifdef LOCAL_TEST

void dump(Node *root) {
  bool first = true;
  vector<Node*> queue;
  
  cout << "[";
  if (root != nullptr) {
    queue.push_back(root);
  }
  while (!queue.empty()) {
    root = queue[0];
    queue.erase(queue.begin());
    if (root->left != nullptr) {
      queue.push_back(root->left);
    }
    if (root->right != nullptr) {
      queue.push_back(root->right);
    }
    if (!first) {
      cout << "," << root->val;
      if (root->next == nullptr) {
        cout << ",#";
      }
    } else {
      first = false;
      cout << root->val << ",#";
    }
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  Node *root = nullptr;

  root = new Node(
    1,
    new Node(
      2,
      new Node(4),
      new Node(5),
      nullptr
    ),
    new Node(
      3,
      new Node(6),
      new Node(7),
      nullptr
    ),
    nullptr
  );

  dump(s.connect(root));

  return 0;
}

#endif
