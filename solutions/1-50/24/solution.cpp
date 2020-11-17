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
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr) {
      return head;
    }
    if (head->next == nullptr) {
      return head;
    }

    ListNode *next = head->next;
    ListNode *swapped = swapPairs(next->next);

    next->next = head;
    head->next = swapped;

    return next;
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
  ListNode *head;

  head = new ListNode(
      1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
  dump(s.swapPairs(head));
  cout << endl;

  head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
  dump(s.swapPairs(head));
  cout << endl;

  return 0;
}

#endif
