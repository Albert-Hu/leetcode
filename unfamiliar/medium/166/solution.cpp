#include <iostream>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    return "";
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  
  cout << s.fractionToDecimal(1, 2) << endl;
  cout << s.fractionToDecimal(2, 1) << endl;
  cout << s.fractionToDecimal(2, 3) << endl;
  cout << s.fractionToDecimal(4, 333) << endl;
  cout << s.fractionToDecimal(1, 6) << endl;
  cout << s.fractionToDecimal(1, 17) << endl;

  return 0;
}

#endif
