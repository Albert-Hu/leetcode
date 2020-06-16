#include <iostream>
#include <vector>
#include <functional>

using namespace std;

class Solution {
public:
  vector<vector<string> > partition(string s) {
    vector<vector<string> > palindromes;
    vector<string> list;

    function<bool(string&)> verify = [](string &str) {
      int endIndex = str.length() - 1;
      int halfLength = str.length() / 2;
      for (int index = 0; index < halfLength; ++index) {
        if (str[index] != str[endIndex - index]) {
          return false;
        }
      }
      return true;
    };

    function<void(string&)> search = [&](string &str) {
      if (verify(str)) {
        list.push_back(str);
        palindromes.push_back(list);
        list.pop_back();
      }
      for (int length = 1; length < str.length(); ++length) {
        string leftSubstring = str.substr(0, length);
        if (verify(leftSubstring)) {
          string rightSubstring = str.substr(length);
          list.push_back(leftSubstring);
          search(rightSubstring);
          list.pop_back();
        }
      }
    };

    search(s);

    return palindromes;
  }
};

#ifdef LOCAL_TEST

void dump(vector<vector<string> > palindromes) {
  cout << "[" << endl;
  for (int i = 0; i < palindromes.size(); ++i) {
    cout << "  [";
    for (int j = 0; j < palindromes[i].size(); ++j) {
      if (j > 0) cout << ", ";
      cout << palindromes[i][j];
    }
    cout << "]" << (i < (palindromes.size() - 1) ? "," : "") << endl;
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;

  dump(s.partition("aab"));

  return 0;
}

#endif
