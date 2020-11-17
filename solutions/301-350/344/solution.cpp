#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void reverseString(vector<char> &s) {
    int left = 0, right = s.size() - 1;
    while (left < right) {
      swap(s[left++], s[right--]);
    }
  }
};

#ifdef LOCAL_TEST
void dump(vector<char> &s) {
  cout << "[";
  for (int i = 0; i < s.size(); i++) {
    if (i > 0)
      cout << ", ";
    cout << s[i];
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<char> str;

  str.clear();
  str.push_back('h');
  str.push_back('e');
  str.push_back('l');
  str.push_back('l');
  str.push_back('o');
  s.reverseString(str);
  dump(str);

  return 0;
}

#endif
