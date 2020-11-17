#include <iostream>
#include <vector>

using namespace std;

#ifdef LOCAL_TEST
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *node) : val(x), next(node) {}
};
#endif

class Solution {
public:
  void deleteNode(ListNode *node) {
    node->val = node->next->val;
    node->next = node->next->next;
  }
};

#ifdef LOCAL_TEST
void dump(ListNode *node) {
  bool showComma = false;

  cout << "[";
  while (node != nullptr) {
    if (showComma)
      cout << ", ";
    else
      showComma = true;
    cout << node->val;
    node = node->next;
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  ListNode *node = nullptr;

  node = new ListNode(4, new ListNode(5, new ListNode(1, new ListNode(9))));
  s.deleteNode(node);
  dump(node);

  node = new ListNode(4, new ListNode(5, new ListNode(1, new ListNode(9))));
  s.deleteNode(node);
  dump(node);

  return 0;
}

#endif
