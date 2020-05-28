#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
  int calculate(string s) {
    char op = '+';
    int n = s.size() - 1;
    long long int i = 0, result = 0;
    stack<int> integers;
    stack<char> operators;

    for (int j = 0; j < s.size(); ++j) {
      char c = s[j];
      if (c >= '0' && c <= '9') {
        i = i * 10 + c - '0';
      }

      if (c == '+' || c == '-' || c == '(' || c == ')' || j == n) {
        if (c == '(') {
          integers.push(result);
          operators.push(op);
          result = 0;
          op = '+';
        } else {
          switch (op) {
            case '+': result += i; break;
            case '-': result -= i; break;
          }
          if (c == ')') {
            result = (operators.top() == '+')
              ? (integers.top() + result)
              : (integers.top() - result);
            integers.pop();
            operators.pop();
            op = '+';
          } else {
            op = c;
          }
        }
        i = 0;
      }
    }

    return (int) result;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  cout << s.calculate("1 + 2 + 3") << endl;
  cout << s.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
  return 0;
}

#endif
