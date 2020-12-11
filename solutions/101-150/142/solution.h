#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <iostream>
#include <set>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *detectCycle(ListNode *head);
};

#endif /* _SOLUTION_H_ */
