#include <iostream>

using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t reversed = 0;
    for (int bit = 0; bit < 32; bit++) {
      reversed |= ((n >> bit) & 1) << (31 - bit);
    }
    return reversed;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.reverseBits(43261596) << endl;
  cout << s.reverseBits(4294967293) << endl;

  return 0;
}

#endif
