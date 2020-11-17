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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = nullptr;
    ListNode **placeholder = &head;

    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        *placeholder = l1;
        l1 = l1->next;
      } else {
        *placeholder = l2;
        l2 = l2->next;
      }
      placeholder = &(*placeholder)->next;
    }

    if (l1 != nullptr) {
      *placeholder = l1;
    }

    if (l2 != nullptr) {
      *placeholder = l2;
    }

    return head;
  }
};

#ifdef LOCAL_TEST

void dump(ListNode *head) {
  if (head != nullptr) {
    cout << head->val << (head->next == nullptr ? "" : "->");
    dump(head->next);
  }
}

int main(int argc, char *argv[]) {
  Solution s;
  ListNode *l1, *l2;

  l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
  l2 = new ListNode(1, new ListNode(3, new ListNode(4)));

  dump(s.mergeTwoLists(l1, l2));
  cout << endl;

  return 0;
}

#endif
