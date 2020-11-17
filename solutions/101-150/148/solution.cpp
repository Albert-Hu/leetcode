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
  ListNode *sortList(ListNode *head) {
    if (head == nullptr) {
      return head;
    }

    if (head->next == nullptr) {
      return head;
    }

    ListNode *right = sortList(divide(head));
    ListNode *left = sortList(head);

    return merge(left, right);
  }

  ListNode *divide(ListNode *head) {
    ListNode *prev = head;
    ListNode *end = head;

    while (end != nullptr) {
      if (end->next == nullptr) {
        break;
      }
      prev = head;
      head = head->next;
      end = end->next->next;
    }

    if (prev != nullptr) {
      prev->next = nullptr;
    }

    return head;
  }

  ListNode *merge(ListNode *left, ListNode *right) {
    ListNode *head = nullptr;
    ListNode **current = &head;

    while (left != nullptr && right != nullptr) {
      if (left->val < right->val) {
        *current = left;
        left = left->next;
      } else {
        *current = right;
        right = right->next;
      }
      current = &(*current)->next;
    }

    if (left != nullptr) {
      *current = left;
    }

    if (right != nullptr) {
      *current = right;
    }

    return head;
  }
};

#ifdef LOCAL_TEST

void dump(ListNode *head) {
  bool first = true;
  while (head != nullptr) {
    if (first) {
      first = false;
    } else {
      cout << "->";
    }
    cout << head->val;
    head = head->next;
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  ListNode *head;
  ListNode *next;

  head = next = new ListNode(4);
  next->next = new ListNode(2);
  next = next->next;
  next->next = new ListNode(1);
  next = next->next;
  next->next = new ListNode(3);
  dump(s.sortList(head));

  head = next = new ListNode(-1);
  next->next = new ListNode(5);
  next = next->next;
  next->next = new ListNode(3);
  next = next->next;
  next->next = new ListNode(4);
  next = next->next;
  next->next = new ListNode(0);
  dump(s.sortList(head));

  return 0;
}

#endif
