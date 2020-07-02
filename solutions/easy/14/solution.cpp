#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    int minimumLength = 0;
    string prefix;

    if (strs.size() > 0) {
      minimumLength = strs[0].length();
      for (int i = 1; i < strs.size(); i++) {
        if (strs[i].length() < minimumLength) {
          minimumLength = strs[i].length();
        }
      }
    }

    for (int index = 0; index < minimumLength; index++) {
      bool done = false;
      char c = strs[0][index];
      for (int s = 1; s < strs.size(); s++) {
        if (strs[s][index] != c) {
          done = true;
          break;
        }
      }
      if (done) {
        break;
      }
      prefix.push_back(c);
    }

    return prefix;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<string> strs;

  strs.push_back("flower");
  strs.push_back("flow");
  strs.push_back("flight");
  cout << s.longestCommonPrefix(strs) << endl;

  strs.clear();
  strs.push_back("dog");
  strs.push_back("racecar");
  strs.push_back("car");
  cout << s.longestCommonPrefix(strs) << endl;

  return 0;
}

#endif
