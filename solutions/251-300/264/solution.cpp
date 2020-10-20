#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
      if (n < 1) return 0;

      int index2 = 0, index3 = 0, index5 = 0;
      vector<int> numbers(n, 1);

      for (int i = 1; i < n; i++) {
        int n2 = numbers[index2] * 2;
        int n3 = numbers[index3] * 3;
        int n5 = numbers[index5] * 5;

        numbers[i] = min(n2, min(n3, n5));
        if (numbers[i] == n2) index2++;
        if (numbers[i] == n3) index3++;
        if (numbers[i] == n5) index5++;
      }

      return numbers[n - 1];
    }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.nthUglyNumber(1) << endl;
  cout << s.nthUglyNumber(10) << endl;
  cout << s.nthUglyNumber(11) << endl;
  cout << s.nthUglyNumber(1690) << endl;

  return 0;
}

#endif
