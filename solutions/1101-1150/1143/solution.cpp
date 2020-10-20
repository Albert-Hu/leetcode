#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int> > dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
    
    for (int i = 0; i < text1.length(); i++) {
      for (int j = 0; j < text2.length(); j++) {
        if (text1[i] == text2[j]) {
          dp[i + 1][j + 1] = dp[i][j] + 1;
        } else {
          dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
      }
    }

    return dp.back().back();
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.longestCommonSubsequence("abcde", "ace") << endl;
  cout << s.longestCommonSubsequence("abc", "abc") << endl;
  cout << s.longestCommonSubsequence("abc", "def") << endl;

  return 0;
}

#endif
