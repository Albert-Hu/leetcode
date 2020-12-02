#include <iomanip>
#include <iostream>
#include <sstream>

#include "solution.h"

using namespace std;

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

bool get_answer(int &answer) {
  string line;
  getline(cin, line);
  istringstream iss(line);

  return (iss >> answer) ? true : false;
}

int main(int argc, char *argv[]) {
  int test_case = 1;

  while (1) {
    int answer;
    vector<int> array;
    Solution s;

    if (!get_array(array))
      break;
    if (!get_answer(answer))
      break;

    cout << "Test " << std::left << setw(3) << test_case++ << ": ";
    if (s.firstMissingPositive(array) == answer) {
      cout << "[PASS]";
    } else {
      cout << "[FAIL]";
    }
    cout << endl;
  }

  return 0;
}
