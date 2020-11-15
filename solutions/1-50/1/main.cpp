#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>

#include "solution.h"

using namespace std;

bool get_answer(vector<int> &answer) {
  int n;
  string line;
  getline(cin, line);
  istringstream iss(line);

  while (iss >> n) {
    answer.push_back(n);
  }

  return answer.size() == 2;
}

bool get_array(vector<int> &array) {
  int n;
  string line;
  getline(cin, line);
  istringstream iss(line);

  while (iss >> n) {
    array.push_back(n);
  }

  return array.size() >= 2;
}

bool get_target(int &target) {
  string line;
  getline(cin, line);
  istringstream iss(line);

  return (iss >> target) ? true : false;
}

int main(int argc, char *argv[]) {
  int test_case = 1;
  while (1) {
    int target;
    vector<int> array;
    vector<int> answer;

    if (!get_target(target)) break;
    if (!get_array(array)) break;
    if (!get_answer(answer)) break;

    Solution solution;
    vector<int> result = solution.twoSum(array, target);

    cout << "Test " << std::left << setw(3) << test_case++ << ": ";
    if (result.size() != 2) {
      cout << "[FAIL]";
    } else {
      if (max(result[0], result[1]) == max(answer[0], answer[1]) && min(result[0], result[1]) == min(answer[0], answer[1])) {
        cout << "[PASS]";
      } else {
        cout << "[FAIL]";
      }
    }
    cout << endl;

  }
#if 0
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
#endif
  return 0;
}
