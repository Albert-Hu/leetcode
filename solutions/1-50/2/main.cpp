#include <iomanip>
#include <iostream>
#include <sstream>

#include "solution.h"

using namespace std;

void dump(ListNode *root) {
  while (root != nullptr) {
    cout << root->val;
    root = root->next;
  }
  cout << endl;
}

string listNodeTostr(ListNode *root) {
  string str;

  while (root != nullptr) {
    str.push_back(root->val + '0');
    root = root->next;
  }

  return str;
}

ListNode *strToListNode(string &str) {
  ListNode *root = nullptr;
  ListNode **n = &root;

  for (auto c : str) {
    *n = new ListNode(c - '0');
    n = &(*n)->next;
  }

  return root;
}

int main(int argc, char *argv[]) {
  int test_case = 1;
  
  while (1) {
    string s1, s2, answer;
    ListNode *l1, *l2, *result;
    Solution solution;

    if (!(cin >> s1))
      break;
    if (!(cin >> s2))
      break;
    if (!(cin >> answer))
      break;

    l1 = strToListNode(s1);
    l2 = strToListNode(s2);

    result = solution.addTwoNumbers(l1, l2);

    cout << "Test " << std::left << setw(3) << test_case++ << ": ";
    if (result != nullptr && listNodeTostr(result) == answer) {
      cout << "[PASS]";
    } else {
      cout << "[FAIL]";
    }
    cout << endl;

  }

  return 0;
}
