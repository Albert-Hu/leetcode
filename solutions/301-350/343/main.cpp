#include <iostream>
#include <iomanip>
#include <vector>

#include "solution.h"

using namespace std;

int main(int argc, char *argv[]) {
  Solution s;
  vector<pair<int, int>> testCase = {
    {2, 1},
    {3, 2},
    {4, 4},
    {5, 6},
    {10, 36}
  };
  
  for (auto test : testCase) {
    int result = s.integerBreak(test.first);
    cout << "Input: " << setw(2) << test.first << " ... ";
    cout << ((result == test.second) ? "[PASS]" : "[FAIL]") << endl;
  }

  return 0;
}
