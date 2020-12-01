#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

class Solution {
public:
  void search(string &num, int target, ll previous, ll result, string e, vector<string> &expressions);
  vector<string> addOperators(string num, int target);
};

#endif /* _SOLUTION_H_ */
