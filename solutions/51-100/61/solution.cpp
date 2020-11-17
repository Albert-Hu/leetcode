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
  ListNode *rotateRight(ListNode *head, int k) {
    int l;
    ListNode *a;

    l = len(head);
    k = (l > 0) ? (k % l) : 0;
    l = l - k - 1;

    a = head;
    for (int i = 0; i < l; ++i) {
      a = a->next;
    }

    for (ListNode *b = a; b != nullptr; b = b->next) {
      if (b->next == nullptr) {
        if (a->next != nullptr) {
          ListNode *tmp = head;
          head = a->next;
          a->next = nullptr;
          b->next = tmp;
        }
        break;
      }
    }

    return head;
  }

private:
  int len(ListNode *head) {
    int l = 0;

    while (head != nullptr) {
      head = head->next;
      ++l;
    }

    return l;
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
  dump(s.rotateRight(head, 2));
  cout << endl;

  head = new ListNode(0, new ListNode(1, new ListNode(2)));
  dump(s.rotateRight(head, 4));
  cout << endl;

  head = new ListNode(0, new ListNode(1, new ListNode(2)));
  dump(s.rotateRight(head, 3));
  cout << endl;

  head = new ListNode(0, new ListNode(1, new ListNode(2)));
  dump(s.rotateRight(head, 0));
  cout << endl;

  head = new ListNode(1);
  dump(s.rotateRight(head, 0));
  cout << endl;

  return 0;
}

#endif
