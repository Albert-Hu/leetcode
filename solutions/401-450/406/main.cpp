#include <iomanip>
#include <iostream>
#include <regex>

#include "solution.h"

using namespace std;

string remove_space(string line) {
  string new_line;

  for (auto c : line) {
    new_line.push_back(c);
  }

  return new_line;
}

bool get_array(vector<vector<int>> &array) {
  int n = 0;
  string line;
  vector<int> v;
  regex expression("\\[\\[\\d+,\\d+\\](,\\[\\d+,\\d+\\])*\\]");

  if (!(getline(cin, line)))
    return false;

  line = remove_space(line);

  if (!regex_match(line, expression))
    return false;

  for (auto c : line) {
    if (c >= '0' && c <= '9') {
      n = n * 10 + (c - '0');
    } else if (c == ',') {
      if (v.size() == 2) {
        array.push_back(v);
        v.clear();
      }
      v.push_back(n);
      n = 0;
    }
  }
  v.push_back(n);
  array.push_back(v);

  return true;
}

bool verify(vector<vector<int>> &result, vector<vector<int>> &answer) {
  if (result.size() != answer.size())
    return false;

  for (unsigned int i = 0; i < answer.size(); i++) {
    if (result[i].size() != answer[i].size())
      return false;
    for (unsigned int j = 0; j < answer[i].size(); j++) {
      if (result[i][j] != answer[i][j])
        return false;
    }
  }

  return true;
}

void dump(vector<vector<int>> &array) {
  cout << "[";
  for (unsigned int i = 0; i < array.size(); i++) {
    if (i > 0)
      cout << ",";
    cout << "[";
    for (unsigned int j = 0; j < array[i].size(); j++) {
      if (j > 0)
        cout << ",";
      cout << array[i][j];
    }
    cout << "]";
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  int test_case = 1;

  while (1) {
    Solution s;
    vector<vector<int>> input;
    vector<vector<int>> output;
    vector<vector<int>> answer;

    if (!get_array(input))
      break;
    if (!get_array(answer))
      break;

    output = s.reconstructQueue(input);

    cout << "Test " << std::left << setw(3) << test_case++ << ": ";
    if (verify(output, answer)) {
      cout << "[PASS]";
    } else {
      cout << "[FAIL]";
    }
    cout << endl;
  }

  return 0;
}
