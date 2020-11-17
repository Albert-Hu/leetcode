#include <iostream>
#include <vector>

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
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    bool done = false;
    ListNode *head = nullptr;
    ListNode **iterator = &head;

    while (!done) {
      if (lists.empty())
        break;
      done = true;
      for (int i = 0; i < lists.size(); i++) {
        if (lists[i] == nullptr) {
          done = false;
          lists.erase(lists.begin() + i);
          break;
        }
      }
    }

    while ((*iterator = getNode(lists)) != nullptr) {
      iterator = &(*iterator)->next;
    }
    *iterator = nullptr;

    return head;
  }

  ListNode *getNode(vector<ListNode *> &lists) {
    if (lists.size() == 0)
      return nullptr;

    int index = 0;
    ListNode *node = nullptr;
    for (int i = 1; i < lists.size(); i++) {
      if (lists[index]->val > lists[i]->val) {
        index = i;
      }
    }

    node = lists[index];
    if (lists[index]->next == nullptr) {
      lists.erase(lists.begin() + index);
    } else {
      lists[index] = lists[index]->next;
    }

    return node;
  }
};

#ifdef LOCAL_TEST
void dump(ListNode *head) {
  while (head != nullptr) {
    cout << head->val;
    if (head->next != nullptr)
      cout << "->";
    head = head->next;
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<ListNode *> lists;

  lists.push_back(new ListNode(1, new ListNode(4, new ListNode(5))));
  lists.push_back(new ListNode(1, new ListNode(3, new ListNode(4))));
  lists.push_back(new ListNode(2, new ListNode(6)));
  dump(s.mergeKLists(lists));

  return 0;
}
#endif
