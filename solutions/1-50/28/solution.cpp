#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.length() == 0)
      return 0;

    if (haystack.length() == 0)
      return -1;
    
    int end = haystack.length() - needle.length() + 1;
    for (int index = 0; index < end; index++) {
      int n = 0;
      while (n < needle.length()) {
        if (needle[n] != haystack[index + n]) {
          break;
        }
        n++;
      }
      if (n == needle.length())
        return index;
    }

    return -1;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << s.strStr("hello", "ll") << endl;
  cout << s.strStr("aaaaa", "bba") << endl;

  return 0;
}

#endif
