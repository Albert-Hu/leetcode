#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

#include "solution.h"

using namespace std;

bool get_answer(vector<string> &answer) {
  if (cin.eof()) return false;

  string s;
  string line;
  getline(cin, line);
  istringstream iss(line);

  while (iss >> s) {
    answer.push_back(s);
  }

  return true;
}

bool get_target(int &target) {
  if (cin.eof()) return false;

  string line;
  getline(cin, line);
  istringstream iss(line);

  iss >> target;

  return true;
}

bool get_number(string &number) {
  if (cin.eof()) return false;

  string line;
  getline(cin, line);
  istringstream iss(line);

  iss >> number;

  return true;
}

bool verify(vector<string> &results, vector<string> &answer) {
  if (results.size() != answer.size())
    return false;

  sort(results.begin(), results.end());
  sort(answer.begin(), answer.end());

  for (unsigned int i = 0; i < answer.size(); i++) {
    if (results[i] != answer[i]) return false;
  }

  return true;
}

int main(int argc, char *argv[]) {
  int test_case = 1;

  while (1) {
    Solution s;
    int target;
    string numbers;
    vector<string> answer;
    vector<string> results;

    if (!get_number(numbers)) break;
    if (!get_target(target)) break;
    if (!get_answer(answer)) break;
#if 0
    cout << "Number: " << numbers << endl;
    cout << "Target: " << target << endl;
    cout << "Answer:";
    for (auto ans : answer) cout << " " << ans;
    cout << endl;
#endif
    results = s.addOperators(numbers, target);
/*
    cout << "Results:";
    for (auto r : results) cout << " " << r;
    cout << endl;
*/
    cout << "Test " << std::left << setw(3) << test_case++ << ": ";
    if (verify(results, answer)) {
      cout << "[PASS]";
    } else {
      cout << "[FAIL]";
    }
    cout << endl;
  }

  return 0;
}
