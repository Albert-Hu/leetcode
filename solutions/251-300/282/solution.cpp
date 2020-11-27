#include <iostream>

#define C2I(c) static_cast<int>(c - '0')

#ifdef LOCAL_TEST
#include "solution.h"
#else

using namespace std;

class Solution {
public:
  bool canCompute(string &expression);
  int compute(string &expression);
  void search(string &expression, unsigned int op, int target);
  vector<string> addOperators(string num, int target);
private:
  set<string> ignore;
  vector<string> results;
};

#endif

bool Solution::canCompute(string &expression) {
  for (unsigned int i = 1; i < expression.length(); i += 2) {
    if (expression[i] == ' ') {
      if (expression[i - 1] == '0')
        return false;
    }
  }
  return true;
}

int Solution::compute(string &expression) {
  vector<int> numbers;
  vector<char> operators;

  numbers.push_back(C2I(expression.front()));
  for (unsigned int i = 1; i < expression.size(); i += 2) {
    if (expression[i] == ' ') {
      int last = numbers.size() - 1;
      numbers[last] = numbers[last] * 10 + C2I(expression[i + 1]);
    } else {
      numbers.push_back(C2I(expression[i + 1]));
      operators.push_back(expression[i]);
    }
  }

  // Pass 1 - Process all multiplications.
  for (unsigned int i = 0; i < operators.size(); i++) {
    if (operators[i] == '*') {
      numbers[i + 1] = numbers[i] * numbers[i + 1];
      numbers[i] = 0;
      if (i > 0) {
        operators[i] = operators[i - 1];
      } else {
        operators[i] = '+';
      }
    }
  }

  // Pass 2 - Process remained operations.
  for (unsigned int i = 0; i < operators.size(); i++) {
    if (operators[i] == '+') {
      numbers[i + 1] = numbers[i] + numbers[i + 1];
    } else {
      numbers[i + 1] = numbers[i] - numbers[i + 1];
    }
  }

  return numbers.back();
}

void Solution::search(string &expression, unsigned int op, int target) {
  if (op > expression.length()) {
    if (ignore.count(expression) == 0) {
      do {
        if (!canCompute(expression))
          break;
        if (target != compute(expression))
          break;
        string answer;
        for (auto c : expression) {
          if (c != ' ') answer.push_back(c);
        }
        results.push_back(answer);

        //cout << answer << "=" << compute(expression) << "(" << target << ")" << endl;
      } while (0);
      ignore.insert(expression);
    }
  } else {
    expression[op] = '+';
    search(expression, op + 2, target);
    expression[op] = '-';
    search(expression, op + 2, target);
    expression[op] = '*';
    search(expression, op + 2, target);
    expression[op] = ' ';
    search(expression, op + 2, target);
  }
}

vector<string> Solution::addOperators(string num, int target) {
  if (num.length() > 0) {
    string expression;

    expression.push_back(num[0]);
    for (unsigned int i = 1; i < num.length(); i++) {
      expression.push_back(' ');
      expression.push_back(num[i]);
    }

    search(expression, 1, target);
  }

  return results;
}
