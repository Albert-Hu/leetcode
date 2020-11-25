#include <iostream>
#include <iomanip>
#include <vector>
#include "solution.h"

int main(int argc, char *argv[]) {
  int test_case = 1;
  while (1) {
    Solution solution;
    int answer = 0;
    string s;
    string a;

    if (cin.eof()) break;
    getline(cin, s);

    if (cin.eof()) break;
    getline(cin, a);
    answer = stoi(a);

    cout << "Test " << std::left << setw(3) << test_case++ << ": ";
    if (solution.lengthOfLongestSubstring(s) == answer) {
      cout << "[PASS]";
    } else {
      cout << "[FAIL]";
    }
    cout << endl;
  }
  return 0;
}
