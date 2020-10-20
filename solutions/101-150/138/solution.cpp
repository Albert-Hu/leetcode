#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

#ifdef LOCAL_TEST

class Node {
public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

#endif

class Solution {
public:
  Node* copyRandomList(Node* head) {
    int index = 0;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node* node = head;
    unordered_map<Node*,int> table;
    vector<Node*> list;

    while (node != nullptr) {
      table[node] = index;
      next = new Node(node->val);
      list.push_back(next);
      if (prev != nullptr) {
        prev->next = next;
      }
      prev = next;
      index++;
      node = node->next;
    }

    index = 0;
    node = head;
    while (node != nullptr) {
      if (table.find(node->random) != table.end()) {
        list[index]->random = list[table[node->random]];
      }
      index++;
      node = node->next;
    }

    return (list.size() > 0) ? list[0] : nullptr;
  }
};

#ifdef LOCAL_TEST

void dump(Node *head) {
  bool comma = false;
  vector<Node*> array;

  while (head != nullptr) {
    array.push_back(head);
    head = head->next;
  }

  cout << "[";
  for (int i = 0; i < array.size(); i++) {
    if (i > 0) cout << ",";
    cout << "[";
    cout << array[i]->val << ",";
    if (array[i]->random != nullptr) {
      for (int j = 0; j < array.size(); j++) {
        if (array[i]->random == array[j]) {
          cout << j;
          break;
        }
      }
    } else {
      cout << "null";
    }
    cout << "]";
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<Node*> linkedList;

  linkedList.push_back(new Node(7));
  linkedList.push_back(new Node(13));
  linkedList.push_back(new Node(11));
  linkedList.push_back(new Node(10));
  linkedList.push_back(new Node(1));
  linkedList[0]->next = linkedList[1];
  linkedList[1]->next = linkedList[2];
  linkedList[2]->next = linkedList[3];
  linkedList[3]->next = linkedList[4];
  linkedList[4]->next = nullptr;
  linkedList[0]->random = nullptr;
  linkedList[1]->random = linkedList[0];
  linkedList[2]->random = linkedList[4];
  linkedList[3]->random = linkedList[2];
  linkedList[4]->random = linkedList[0];
  dump(s.copyRandomList(linkedList[0]));

  return 0;
}

#endif
