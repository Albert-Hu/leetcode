#include <iostream>
#include <limits>

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
  bool hasCycle(ListNode *head) {
    ListNode *n = head;

    while (head != nullptr && n != nullptr) {
      if (n->next == nullptr)
        break;
      
      n = n->next->next;
      head = head->next;

      if (head == n && head != nullptr)
        return true;
    }

    return false;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  struct ListNode *head = nullptr;

  head = new ListNode(3);
  head->next = new ListNode(2);
  head->next->next = new ListNode(0);
  head->next->next->next = new ListNode(-4);
  head->next->next->next->next = head->next;
  cout << (s.hasCycle(head) ? "true" : "false") << endl;

  head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = head;
  cout << (s.hasCycle(head) ? "true" : "false") << endl;

  head = new ListNode(1);
  cout << (s.hasCycle(head) ? "true" : "false") << endl;

  head = new ListNode(1);
  head->next = new ListNode(2);
  cout << (s.hasCycle(head) ? "true" : "false") << endl;

  return 0;
}

#endif
