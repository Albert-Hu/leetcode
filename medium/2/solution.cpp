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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode *result = nullptr;
    ListNode **l3 = &result;

    while (l1 != nullptr && l2 != nullptr) {
      carry = carry + l1->val + l2->val;
      *l3 = new ListNode(carry % 10);
      carry /= 10;
      l3 = &(*l3)->next;
      l1 = l1->next;
      l2 = l2->next;
    }

    while (l1 != nullptr) {
      carry = carry + l1->val;
      *l3 = new ListNode(carry % 10);
      carry /= 10;
      l3 = &(*l3)->next;
      l1 = l1->next;
    }

    while (l2 != nullptr) {
      carry = carry + l2->val;
      *l3 = new ListNode(carry % 10);
      carry /= 10;
      l3 = &(*l3)->next;
      l2 = l2->next;
    }

    if (carry != 0) {
      *l3 = new ListNode(carry);
    }

    return result;
  }
};

#ifdef LOCAL_TEST

void dump(ListNode *l) {
  if (l != nullptr) {
    dump(l->next);
    cout << l->val;
  }
}

int main(int argc, char *argv[]) {
  Solution s;
  ListNode *l1, *l2;

  l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
  l2 = new ListNode(5, new ListNode(6, new ListNode(4)));

  dump(s.addTwoNumbers(l1, l2));
  cout << endl;

  return 0;
}

#endif
