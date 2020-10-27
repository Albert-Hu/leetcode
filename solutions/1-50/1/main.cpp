#include <iostream>
#include <vector>

#include "solution.h"

using namespace std;

int main(int argc, char *argv[]) {
  /*
    Format of Test Case:
    {{test}, {answer}}
    Format of Test:
    {target, array}
  */
  vector<pair<pair<int, vector<int> >, vector<int> > > testCase = {
    {{9, {2, 7, 11, 15}}, {0, 1}},
    {{6, {3, 2, 4}}, {1, 2}},
    {{6, {3, 3}}, {0, 1}},
    {{6, {1, 3, 5}}, {0, 2}},
    {{4, {1, 3, 5}}, {0, 1}},
    {{8, {1, 3, 5}}, {1, 2}}
  };

  for (unsigned int i = 0; i < testCase.size(); i++) {
    Solution s;
    vector<int> answer = s.twoSum(testCase[i].first.second, testCase[i].first.first);
    cout << "Test " << (i + 1) << " ... ";
    if (answer.size() != 2) {
      cout << "[FAIL]";
    } else {
      if (answer[0] == testCase[i].second.at(0) && answer[1] == testCase[i].second.at(1)) {
        cout << "[PASS]";
      } else {
        cout << "[FAIL]";
      }
    }
    cout << endl;
  }

  return 0;
}
