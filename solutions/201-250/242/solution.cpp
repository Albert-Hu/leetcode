#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    vector<int> count(26, 0);

    for (auto c : s) {
      int index = static_cast<int>(c - 'a');
      count[index]++;
    }

    for (auto c : t) {
      int index = static_cast<int>(c - 'a');
      count[index]--;
    }

    for (auto c : count)
      if (c != 0)
        return false;

    return true;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << (s.isAnagram("anagram", "nagaram") ? "true" : "false") << endl;
  cout << (s.isAnagram("rat", "car") ? "true" : "false") << endl;

  return 0;
}

#endif
