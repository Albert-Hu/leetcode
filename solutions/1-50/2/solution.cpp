#include <iostream>
using namespace std;

#ifdef LOCAL_TEST

#include "solution.h"

#else

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
};

#endif

ListNode *Solution::addTwoNumbers(ListNode *l1, ListNode *l2) {
  int carry = 0;
  ListNode *root = nullptr;
  ListNode **current = &root;

  while (l1 != nullptr && l2 != nullptr) {
    carry = carry + l1->val + l2->val;
    *current = new ListNode(carry % 10);
    carry /= 10;
    current = &(*current)->next;
    l1 = l1->next;
    l2 = l2->next;
  }

  while (l1 != nullptr) {
    carry = carry + l1->val;
    *current = new ListNode(carry % 10);
    carry /= 10;
    current = &(*current)->next;
    l1 = l1->next;
  }

  while (l2 != nullptr) {
    carry = carry + l2->val;
    *current = new ListNode(carry % 10);
    carry /= 10;
    current = &(*current)->next;
    l2 = l2->next;
  }

  if (carry > 0) {
    *current = new ListNode(carry);
  }

  return root;
}
