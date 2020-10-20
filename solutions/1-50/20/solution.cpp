#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
  bool isValid(string str) {
    stack<char> s;

    if (str.length() > 0) {
      s.push(str[0]);
    }

    for (int i = 1; i < str.length(); i++) {
      if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
        s.push(str[i]);
      } else {
        if (s.size() == 0) {
          return false;
        }
        if (str[i] == ')' && s.top() == '(') {
          s.pop();
        } else if (str[i] == ']' && s.top() == '[') {
          s.pop();
        } else if (str[i] == '}' && s.top() == '{') {
          s.pop();
        } else {
          break;
        }
      }
    }

    return s.empty();
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  cout << (s.isValid("()") ? "true" : "false") << endl;
  cout << (s.isValid("()[]{}") ? "true" : "false") << endl;
  cout << (s.isValid("(]") ? "true" : "false") << endl;
  cout << (s.isValid("([)]") ? "true" : "false") << endl;
  cout << (s.isValid("{[]}") ? "true" : "false") << endl;

  return 0;
}

#endif
