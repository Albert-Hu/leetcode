#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    if (n == 1)
      return 1;
    if (n == 2)
      return 2;
    if (steps.count(n) > 0)
      return steps[n];

    steps[n] = climbStairs(n - 1) + climbStairs(n - 2);

    return steps[n];
  }

private:
  map<int, int> steps;
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.climbStairs(2) << endl;
  cout << s.climbStairs(3) << endl;

  return 0;
}

#endif
