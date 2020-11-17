#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool wordBreak(string s, vector<string> &wordDict) {
    return wordBreak(s, wordDict, 0);
  }

  bool wordBreak(string &s, vector<string> &wordDict, int start) {
    if (start == s.length()) {
      return true;
    }
    string substr = s.substr(start);
    for (auto word : wordDict) {
      if ((visitedIndex[word].count(start) == 0) && isSubstr(substr, word)) {
        visitedIndex[word].insert(start);
        if (wordBreak(s, wordDict, start + word.length())) {
          return true;
        }
      }
    }
    return false;
  }

  bool isSubstr(string &str, string &sub) {
    if (str.length() < sub.length()) {
      return false;
    }
    for (int index = 0; index < sub.length(); index++) {
      if (str[index] != sub[index]) {
        return false;
      }
    }
    return true;
  }

private:
  unordered_map<string, unordered_set<int>> visitedIndex;
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution *s;
  vector<string> wordDict;
  string str;

  s = new Solution;
  str = "leetcode";
  wordDict.push_back("leet");
  wordDict.push_back("code");
  cout << (s->wordBreak(str, wordDict) ? "true" : "false") << endl;

  s = new Solution;
  str = "applepenapple";
  wordDict.clear();
  wordDict.push_back("apple");
  wordDict.push_back("pen");
  cout << (s->wordBreak(str, wordDict) ? "true" : "false") << endl;

  s = new Solution;
  str = "catsandog";
  wordDict.clear();
  wordDict.push_back("cats");
  wordDict.push_back("dog");
  wordDict.push_back("sand");
  wordDict.push_back("and");
  wordDict.push_back("cat");
  cout << (s->wordBreak(str, wordDict) ? "true" : "false") << endl;

  return 0;
}

#endif
