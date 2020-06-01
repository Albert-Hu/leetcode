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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int m = 0;
    ListNode **placeholder = &head;
    ListNode *iterator = head;

    while (iterator != nullptr) {
      if (m >= n) {
        placeholder = &(*placeholder)->next;
      }
      iterator = iterator->next;
      ++m;
    }

    *placeholder = (*placeholder)->next;

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

  head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  dump(s.removeNthFromEnd(head, 2));
  cout << endl;

  head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  dump(s.removeNthFromEnd(head, 1));
  cout << endl;

  head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  dump(s.removeNthFromEnd(head, 5));
  cout << endl;

  return 0;
}

#endif
