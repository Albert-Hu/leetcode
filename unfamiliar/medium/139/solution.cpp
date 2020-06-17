#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    return false;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<string> wordDict;
  string str;

  str = "leetcode";
  wordDict.push_back("leet");
  wordDict.push_back("code");
  cout << (s.wordBreak(str, wordDict) ? "true" : "false") << endl;

  str = "applepenapple";
  wordDict.clear();
  wordDict.push_back("apple");
  wordDict.push_back("pen");
  cout << (s.wordBreak(str, wordDict) ? "true" : "false") << endl;

  str = "catsandog";
  wordDict.clear();
  wordDict.push_back("cats");
  wordDict.push_back("dog");
  wordDict.push_back("sand");
  wordDict.push_back("and");
  wordDict.push_back("cat");
  cout << (s.wordBreak(str, wordDict) ? "true" : "false") << endl;

  return 0;
}

#endif
