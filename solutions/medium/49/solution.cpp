#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  vector<vector<string> > groupAnagrams(vector<string>& strs) {
    vector<vector<string> > results;
    map<string, vector<string> > table;

    for (auto str : strs) {
      string clone = str;
      sort(clone.begin(), clone.end());
      table[clone].push_back(str);
    }

    for (auto it : table) {
      results.push_back(it.second);
    }

    return results;
  }
};

#ifdef LOCAL_TEST

void dump(vector<vector<string> > results) {
  cout << "[" << endl;
  for (int i = 0; i < results.size(); ++i) {
    cout << "[";
    for (int j = 0; j < results[i].size(); ++j) {
      if (j > 0) cout << ", ";
      cout << results[i][j];
    }
    cout << "]" << endl;
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<string> strs;

  strs.push_back("eat");
  strs.push_back("tea");
  strs.push_back("tan");
  strs.push_back("ate");
  strs.push_back("nat");
  strs.push_back("bat");
  dump(s.groupAnagrams(strs));

  return 0;
}

#endif
