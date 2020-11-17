#include <iomanip>
#include <iostream>
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

    if (!get_target(target))
      break;
    if (!get_array(array))
      break;
    if (!get_answer(answer))
      break;

    Solution solution;
    vector<int> result = solution.twoSum(array, target);

    cout << "Test " << std::left << setw(3) << test_case++ << ": ";
    if (result.size() != 2) {
      cout << "[FAIL]";
    } else {
      if (max(result[0], result[1]) == max(answer[0], answer[1]) &&
          min(result[0], result[1]) == min(answer[0], answer[1])) {
        cout << "[PASS]";
      } else {
        cout << "[FAIL]";
      }
    }
    cout << endl;
  }
  return 0;
}
