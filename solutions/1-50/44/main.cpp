#include <iomanip>
#include <iostream>

#include "solution.h"

using namespace std;

int main(int argc, char *argv[]) {
  int test_case = 1;

  while (1) {
    string str;
    string pattern;
    string ans;
    Solution s;

    if (!getline(cin, str)) break;

    if (!getline(cin, pattern)) break;

    if (!getline(cin, ans)) break;

    cout << "Test " << std::left << setw(3) << test_case++ << ": ";
    if (s.isMatch(str, pattern) == (ans[0] == '0' ? 0 : 1)) {
      cout << "[PASS]";
    } else {
      cout << "[FAIL]";
    }
    cout << endl;
  }

  return 0;
}
