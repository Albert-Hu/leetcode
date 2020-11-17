#include <iostream>
#include <map>
#include <math.h>

using namespace std;

class Solution {
public:
  int numSquares(int n) {
    if (numbers.count(n) > 0) {
      return numbers[n];
    }

    int min = n;
    int sr = sqrt(n);

    for (int i = sr; i > 0; i--) {
      int squart = i * i;
      if ((n % squart) == 0) {
        int quotient = n / squart;
        if (quotient < min) {
          min = quotient;
        }
      } else {
        int num = (n / squart) + numSquares(n % squart);
        if (num < min) {
          min = num;
        }
      }
    }
    numbers[n] = min;

    return min;
  }

private:
  map<int, int> numbers;
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.numSquares(12) << endl;
  cout << s.numSquares(13) << endl;

  return 0;
}

#endif
