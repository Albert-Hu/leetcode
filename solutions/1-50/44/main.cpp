#include <iomanip>
#include <iostream>

#include "solution.h"

using namespace std;

int main(int argc, char *argv[]) {
  int test_case = 1;

  while (1) {
    string str;
    string pattern;
    bool ans;
    Solution s;

    if (!(cin >> str))
      break;
    if (!(cin >> pattern))
      break;
    if (!(cin >> ans))
      break;

    cout << "Test " << std::left << setw(3) << test_case++ << ": ";
    if (s.isMatch(str, pattern) == ans) {
      cout << "[PASS]";
    } else {
      cout << "[FAIL]";
    }
    cout << endl;
  }

  return 0;
}
