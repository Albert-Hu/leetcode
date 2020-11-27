#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
  bool canCompute(string &expression);
  int compute(string &expression);
  void search(string &expression, unsigned int op, int target);
  vector<string> addOperators(string num, int target);
private:
  set<string> ignore;
  vector<string> results;
};

#endif /* _SOLUTION_H_ */
