#include <iostream>

using namespace std;

class Solution {
public:
  int hammingWeight(uint32_t n) {
    int count = 0;
    for (int i = 0; i < 32; i++) {
      if ((n >> i) & 1)
        count++;
    }
    return count;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.hammingWeight(11) << endl;
  cout << s.hammingWeight(128) << endl;

  return 0;
}

#endif
