#include <iostream>
using namespace std;

#ifdef LOCAL_TEST

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode **current = &head;
    while (*current != nullptr) {
      if ((*current)->next != nullptr) {
        if ((*current)->val == (*current)->next->val) {
          ListNode *n = (*current)->next;
          while (n != nullptr) {
            if (n->val != (*current)->val) {
              break;
            }
            n = n->next;
          }
          *current = n;
          continue;
        }
      }
      current = &(*current)->next;
    }
    return head;
  }
};

#ifdef LOCAL_TEST

void dump(ListNode* head) {
  if (head != nullptr) {
    cout << head->val << (head->next == nullptr ? "" : "->");
    dump(head->next);
  }
}

int main(int argc, char *argv[]) {
  Solution s;
  ListNode *head;

  head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(4, new ListNode(4, new ListNode(5)))))));
  dump(s.deleteDuplicates(head));
  cout << endl;

  head = new ListNode(1, new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3)))));
  dump(s.deleteDuplicates(head));
  cout << endl;

  head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
  dump(s.deleteDuplicates(head));
  cout << endl;

  return 0;
}

#endif
