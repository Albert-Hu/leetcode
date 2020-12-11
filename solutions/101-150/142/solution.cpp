#ifdef LOCAL_TEST
#include "solution.h"
#else

class Solution {
public:
  ListNode *detectCycle(ListNode *head);
};

#endif

ListNode *Solution::detectCycle(ListNode *head) {
  set<ListNode *> nodes;

  while (head && nodes.count(head) == 0) {
    nodes.insert(head);
    head = head->next;
  }

  return head;
}
