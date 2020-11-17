#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    int count = (n > 2) ? 1 : 0;
    vector<bool> skips(n, false);

    for (int i = 3; i < n; i += 2) {
      if (!skips[i]) {
        if (isPrime(i)) {
          count++;
          int m = n / i;
          for (int j = 3; j <= m; j += 2) {
            skips[i * j] = true;
          }
        }
        skips[i] = true;
      }
    }

    return count;
  }
  bool isPrime(int n) {
    if (n == 2)
      return true;

    if ((n & 1) == 0)
      return false;

    int m = sqrt(n) + 1;
    for (int i = 3; i <= m; i += 2) {
      if ((n % i) == 0)
        return false;
    }

    return true;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.countPrimes(10) << endl;
  cout << s.countPrimes(499979) << endl;

  return 0;
}

#endif
