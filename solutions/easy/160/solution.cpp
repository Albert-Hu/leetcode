#include <iostream>
#include <set>

using namespace std;

#ifdef LOCAL_TEST
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
#endif

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    set<ListNode*> footprint;

    while (headA != nullptr) {
      footprint.insert(headA);
      headA = headA->next;
    }

    while (headB != nullptr) {
      if (footprint.count(headB) > 0)
        return headB;
      footprint.insert(headB);
      headB = headB->next;
    }

    return nullptr;
  }
};

#ifdef LOCAL_TEST

void dump(ListNode *head) {
  cout << "[";
  while (head != nullptr) {
    cout << head->val;
    if (head->next != nullptr)
      cout << ", ";
    head = head->next;
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  ListNode *headA = nullptr;
  ListNode *headB = nullptr;

  headA = new ListNode(4);
  headA->next = new ListNode(1);
  headA->next->next = new ListNode(8);
  headA->next->next->next = new ListNode(4);
  headA->next->next->next->next = new ListNode(5);

  headB = new ListNode(5);
  headB->next = new ListNode(6);
  headB->next->next = headA->next;

  dump(s.getIntersectionNode(headA, headB));

  headA = new ListNode(2);
  headA->next = new ListNode(6);
  headA->next->next = new ListNode(4);

  headB = new ListNode(1);
  headB->next = new ListNode(5);

  dump(s.getIntersectionNode(headA, headB));

  return 0;
}

#endif
