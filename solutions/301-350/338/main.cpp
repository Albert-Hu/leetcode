#include <iostream>
#include <vector>

#include "solution.h"

using namespace std;

bool pass(vector<int> &result, vector<int> &answer) {
  if (result.size() != answer.size())
    return false;

  for (unsigned int i = 0; i < answer.size(); i++) {
    if (result[i] != answer[i])
      return false;
  }

  return true;
}

int main(int argc, char *argv[]) {
  vector<vector<int>> testCases = {
      {0},
      {0, 1},
      {0, 1, 1},
      {0, 1, 1, 2},
      {0, 1, 1, 2, 1},
      {0, 1, 1, 2, 1, 2},
      {0, 1, 1, 2, 1, 2, 2},
  };

  for (unsigned int i = 0; i < testCases.size(); i++) {
    Solution s;
    vector<int> result = s.countBits(i);
    if (pass(result, testCases[i]))
      cout << "Test " << (i + 1) << " ... [PASS]" << endl;
    else
      cout << "Test " << (i + 1) << " ... [FAIL]" << endl;
  }

  return 0;
}
