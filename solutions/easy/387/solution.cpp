#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int firstUniqChar(string s) {
    vector<int> count(26, 0);
    
    for (auto c : s) {
      int index = static_cast<int>(c - 'a');
      count[index]++;
    }

    for (int i = 0; i < s.length(); i++) {
      int index = static_cast<int>(s[i] - 'a');
      if (count[index] == 1) return i;
    }

    return -1;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.firstUniqChar("leetcode") << endl;
  cout << s.firstUniqChar("loveleetcode") << endl;

  return 0;
}

#endif
