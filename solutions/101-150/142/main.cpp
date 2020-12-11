#include <iomanip>
#include <iostream>
#include <vector>

#include "solution.h"

using namespace std;

string remove_space(string line) {
  string newLine;

  for (auto c : line) {
    if (c != ' ')
      newLine.push_back(c);
  }

  return newLine;
}

bool get_list(ListNode **node, ListNode **answer, int position) {
  size_t begin = 0, end;
  string line;
  vector<ListNode *> list;

  *node = nullptr;
  *answer = nullptr;

  if (!getline(cin, line))
    return false;

  if (line.length() == 0)
    return true;

  line = remove_space(line);

  while ((end = line.find(',', begin)) != string::npos) {
    list.push_back(new ListNode(stod(line.substr(begin, end - begin))));
    begin = end + 1;
  }
  list.push_back(new ListNode(stod(line.substr(begin))));

  for (unsigned int i = 1; i < list.size(); i++) {
    list[i - 1]->next = list[i];
  }

  if (position > -1 && static_cast<size_t>(position) < list.size()) {
    (list.back())->next = list[position];
    *answer = list[position];
  }

  *node = list.front();

  return true;
}

bool get_position(int &position) {
  string line;

  if (!(getline(cin, line)))
    return false;

  position = stod(line);

  return true;
}

void dump(ListNode *node, int position) {
  ListNode *n = nullptr;

  while (node && node != n) {
    cout << node->val << " ";
    if (position-- == 0) {
      n = node;
    }
    node = node->next;
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  int test_case = 1;

  while (1) {
    int position;
    ListNode *head;
    ListNode *answer;
    ListNode *result;
    Solution s;

    if (!get_position(position))
      break;

    if (!get_list(&head, &answer, position))
      break;

    result = s.detectCycle(head);

    cout << "Test " << std::left << setw(3) << test_case++ << ": ";
    if (result == answer) {
      cout << "[PASS]";
    } else {
      cout << "[FAIL]";
    }
    cout << endl;
  }

  return 0;
}
