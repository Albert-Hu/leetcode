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
  ListNode* oddEvenList(ListNode* head) {
    ListNode *odd = head;
    ListNode *even = (head != nullptr) ? head->next : nullptr;
    ListNode *evenHead = even;

    while (odd != nullptr && even != nullptr) {
      if (even->next == nullptr) {
        break;
      }
      odd->next = even->next;
      odd = odd->next;
      even->next = odd->next;
      even = even->next;
    }

    if (odd != nullptr) {
      odd->next = evenHead;
    }

    return head;
  }
};

#ifdef LOCAL_TEST

void dump(ListNode *head) {
  bool showComma = false;
  cout << "[";
  while (head != nullptr) {
    if (showComma) cout << ", ";
    else showComma = true;
    cout << head->val;
    head = head->next;
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  ListNode *head;

  head = new ListNode(
    1, new ListNode(
      2, new ListNode(
        3, new ListNode(
          4, new ListNode(5)
        )
      )
    )
  );
  dump(s.oddEvenList(head));

  return 0;
}

#endif
