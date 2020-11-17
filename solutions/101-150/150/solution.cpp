#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> numbers;
    for (auto t : tokens) {
      if ((t[0] >= '0' && t[0] <= '9') || (t[0] == '-' && t.length() > 1)) {
        numbers.push(stoi(t));
      } else {
        int a, b;
        b = numbers.top();
        numbers.pop();
        a = numbers.top();
        numbers.pop();
        switch (t[0]) {
        case '+':
          a += b;
          break;
        case '-':
          a -= b;
          break;
        case '*':
          a *= b;
          break;
        default:
          a /= b;
        }
        numbers.push(a);
      }
    }
    return numbers.top();
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<string> tokens;

  tokens.push_back("2");
  tokens.push_back("1");
  tokens.push_back("+");
  tokens.push_back("3");
  tokens.push_back("*");
  cout << s.evalRPN(tokens) << endl;

  tokens.clear();
  tokens.push_back("4");
  tokens.push_back("13");
  tokens.push_back("5");
  tokens.push_back("/");
  tokens.push_back("+");
  cout << s.evalRPN(tokens) << endl;

  tokens.clear();
  tokens.push_back("10");
  tokens.push_back("6");
  tokens.push_back("9");
  tokens.push_back("3");
  tokens.push_back("+");
  tokens.push_back("-11");
  tokens.push_back("*");
  tokens.push_back("/");
  tokens.push_back("*");
  tokens.push_back("17");
  tokens.push_back("+");
  tokens.push_back("5");
  tokens.push_back("+");
  cout << s.evalRPN(tokens) << endl;

  return 0;
}

#endif
