#ifdef LOCAL_TEST
#include "solution.h"
#else

class Solution {
public:
  ListNode *detectCycle(ListNode *head);
};

#endif

#if USE_HASH

ListNode *Solution::detectCycle(ListNode *head) {
  set<ListNode *> nodes;

  while (head && nodes.count(head) == 0) {
    nodes.insert(head);
    head = head->next;
  }

  return head;
}

#else

ListNode *Solution::detectCycle(ListNode *head) {
  ListNode *slow = head;
  ListNode *fast = head;

  while (fast) {
    fast = fast->next;
    if (fast) {
      fast = fast->next;
    }
    slow = slow->next;
    if (fast == slow)
      break;
  }

  slow = head;
  while (fast && fast != slow) {
    fast = fast->next;
    slow = slow->next;
  }

  return fast;
}

#endif
