#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
  bool isHappy(int n) {
    set<int> numbers;

    while (n != 1) {
      if (numbers.count(n) > 0) {
        return false;
      }
      numbers.insert(n);
      n = next(n);
    }

    return true;
  }

  int next(int n) {
    int number = 0;

    while (n > 0) {
      int i = n % 10;
      number += (i * i);
      n /= 10;
    }

    return number;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << (s.isHappy(19) ? "true" : "false") << endl;
  cout << (s.isHappy(2) ? "true" : "false") << endl;

  return 0;
}

#endif
