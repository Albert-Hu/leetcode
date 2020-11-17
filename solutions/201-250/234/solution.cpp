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
  bool isPalindrome(ListNode *head) {
    if (head == nullptr)
      return true;
    if (head->next == nullptr)
      return true;

    ListNode *a = head;
    ListNode *b = head->next->next;

    while (b != nullptr) {
      if (b->next == nullptr) {
        b = b->next;
      } else {
        b = b->next->next;
      }
      a = a->next;
    }
    a = reverseList(a->next);
    b = head;

    while (a != nullptr) {
      if (a->val != b->val)
        return false;
      a = a->next;
      b = b->next;
    }

    return true;
  }

  ListNode *reverseList(ListNode *head) {
    ListNode *prev = nullptr;

    while (head != nullptr) {
      ListNode *next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }

    return prev;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << (s.isPalindrome(new ListNode(1, new ListNode(2))) ? "true" : "false")
       << endl;
  cout << (s.isPalindrome(new ListNode(
               1, new ListNode(2, new ListNode(2, new ListNode(1)))))
               ? "true"
               : "false")
       << endl;

  return 0;
}

#endif
