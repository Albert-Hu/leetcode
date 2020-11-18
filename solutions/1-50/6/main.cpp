#include <iomanip>
#include <iostream>

#include "solution.h"

using namespace std;

int main(int argc, char *argv[]) {
  int test_case = 1;

  while (1) {
    Solution s;
    int num_row;
    string test;
    string answer;

    if (!(cin >> num_row))
      break;
    if (!(cin >> test))
      break;
    if (!(cin >> answer))
      break;

    cout << "Test " << std::left << setw(3) << test_case++ << ": ";
    if (s.convert(test, num_row) == answer) {
      cout << "[PASS]";
    } else {
      cout << "[FAIL]";
    }
    cout << endl;
  }

  return 0;
}
