#include <iostream>

#ifdef LOCAL_TEST
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif

using namespace std;

class Solution {
public:
#if 1
  // recursively solution
  ListNode *reverseList(ListNode *head) {
    if (head == nullptr)
      return nullptr;
    if (head->next == nullptr)
      return head;
    return reverseList(nullptr, head);
  }
  ListNode *reverseList(ListNode *first, ListNode *second) {
    ListNode *next = second->next;
    second->next = first;
    return (next == nullptr) ? second : reverseList(second, next);
  }
#else
  // iteratively solution
  ListNode *reverseList(ListNode *head) {
    if (head != nullptr) {
      ListNode *prev = nullptr;
      while (head != nullptr) {
        ListNode *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
      }
      head = prev;
    }
    return head;
  }
#endif
};

#ifdef LOCAL_TEST
void dump(ListNode *head) {
  while (head != nullptr) {
    cout << head->val;
    cout << "->";
    head = head->next;
  }
  cout << "NULL" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  ListNode *head = new ListNode(
      1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

  dump(s.reverseList(head));

  return 0;
}

#endif
