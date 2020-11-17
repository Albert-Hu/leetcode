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
  ListNode *partition(ListNode *head, int x) {
    ListNode a, b;
    ListNode *less, *greater;

    less = &a;
    greater = &b;
    while (head != nullptr) {
      if (head->val < x) {
        less->next = head;
        less = less->next;
      } else {
        greater->next = head;
        greater = greater->next;
      }
      head = head->next;
    }
    greater->next = nullptr;
    less->next = b.next;

    return a.next;
    ;
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
      1, new ListNode(
             4, new ListNode(
                    3, new ListNode(2, new ListNode(5, new ListNode(2))))));
  dump(s.partition(head, 3));
  cout << endl;

  return 0;
}

#endif
