#include <iostream>

#ifdef LOCAL_TEST
#include "solution.h"
#else

using namespace std;

typedef long long int ll;

class Solution {
public:
  void search(string &num, int target, ll previous, ll result, string e, vector<string> &expressions);
  vector<string> addOperators(string num, int target);
};

#endif

void Solution::search(string &num, int target, ll previous, ll result, string e, vector<string> &expressions) {
  if (num.length() == 0) {
    if (result == static_cast<ll>(target)) {
      expressions.push_back(e);
    }
  } else {
    for (unsigned int i = 0; i < num.length(); i++) {
      if (i > 0) {
        if (num[0] == '0') break;
      }
      
      string current = num.substr(0, i + 1);
      string next = num.substr(i + 1);
      ll n = stol(current);

      search(next, target, n, result + n, e + '+' + current, expressions);
      search(next, target, -n, result - n, e + '-' + current, expressions);
      search(next, target, n * previous, result - previous + n * previous, e + '*' + current, expressions);
    }
  }
}

vector<string> Solution::addOperators(string num, int target) {
  vector<string> expressions;

  for (unsigned int i = 0; i < num.length(); i++) {
    if (i > 0) {
      if (num[0] == '0') break;
    }
    
    string current = num.substr(0, i + 1);
    string next = num.substr(i + 1);
    ll n = stol(current);
    search(next, target, n, n, current, expressions);
  }

  return expressions;
}
