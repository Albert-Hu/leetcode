#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int count(vector<int> &height, unsigned int begin, unsigned int end);
  int trap(vector<int> &height);
};

#endif /* _SOLUTION_H_ */
