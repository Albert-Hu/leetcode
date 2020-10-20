#include <iostream>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    bool hasPoint = false;
    bool sign = (numerator < 0) ^ (denominator < 0);
    long long int longNumerator = abs(numerator);
    long long int longDenominator = abs(denominator);
    map<string, set<int> > remainders;
    string result;

    if (numerator == 0) return "0";

    while (longNumerator != 0) {
      string quotient;
      if (longNumerator < longDenominator) {
        int zeros = -1;
        if (!hasPoint) {
          if (result.length() == 0) {
            result = "0.";
          } else {
            result.push_back('.');
          }
          hasPoint = true;
        }
        while (longNumerator < longDenominator) {
          zeros++;
          longNumerator *= 10;
        }
        while (zeros-- > 0) {
          quotient.push_back('0');
        }
      }
      quotient = quotient + to_string(longNumerator / longDenominator);
      longNumerator = longNumerator % longDenominator;
      if (hasPoint) {
        if (remainders[quotient].count(longNumerator) > 0) {
          int split = result.find(quotient, result.find('.'));
          string repeat = result.substr(split);
          result = result.substr(0, split) + "(" + repeat + ")";
          break;
        }
        remainders[quotient].insert(longNumerator);
      }
      result += quotient;
    }

    if (sign) result.insert(result.begin(), '-');

    return result;
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
