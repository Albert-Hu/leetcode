#include <iomanip>
#include <iostream>
#include <regex>

#include "solution.h"

using namespace std;

string remove_space(string str) {
  string new_str;

  for (auto c : str) {
    if (c != ' ')
      new_str.push_back(c);
  }

  return new_str;
}

vector<int> parse_array(string s) {
  int num = 0;
  vector<int> array;

  if (s.length() > 2) {
    for (auto c : s) {
      if (c == ',') {
        array.push_back(num);
        num = 0;
      } else if (c >= '0' && c <= '9') {
        num = num * 10 + (c - '0');
      }
    }
    array.push_back(num);
  }

  return array;
}

bool get_candidates(vector<int> &candidates) {
  string line;
  regex expression("\\[(\\d+|\\d+(,\\d)+)\\]");

  if (!getline(cin, line))
    return false;

  line = remove_space(line);

  if (!regex_match(line, expression)) {
    return false;
  }

  candidates = parse_array(line);

  return true;
}

bool get_answer(vector<vector<int>> &answer) {
  size_t begin = 1;
  vector<int> a;
  string line;
  regex expression("\\[((\\[(\\d+|\\d+(,\\d)+)\\])?|\\[(\\d+|\\d+(,\\d)+)\\](,"
                   "\\[(\\d+|\\d+(,\\d)+)\\])*)\\]");

  if (!getline(cin, line))
    return false;

  line = remove_space(line);

  if (!regex_match(line, expression)) {
    return false;
  }

  while (begin != string::npos) {
    size_t end = line.find(']', begin);
    if (end != string::npos) {
      vector<int> array = parse_array(line.substr(begin, end - begin + 1));
      if (array.size() > 0) {
        answer.push_back(array);
      }
      begin = end + 2;
    } else {
      begin = end;
    }
  }

  return true;
}

bool get_target(int &target) {
  string line;
  getline(cin, line);
  istringstream iss(line);

  return (iss >> target) ? true : false;
}

bool verify(vector<vector<int>> &results, vector<vector<int>> &answer) {
  if (results.size() != answer.size()) {
    return false;
  }

  for (unsigned int i = 0; i < results.size(); i++) {
    sort(results[i].begin(), results[i].end());
  }

  for (unsigned int i = 0; i < answer.size(); i++) {
    sort(answer[i].begin(), answer[i].end());
  }

  sort(results.begin(), results.end(), [=](vector<int> &a, vector<int> &b) {
    unsigned int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
      if (a[i++] < b[j++])
        return true;
    }
    return (i < j);
  });

  sort(answer.begin(), answer.end(), [=](vector<int> &a, vector<int> &b) {
    unsigned int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
      if (a[i++] < b[j++])
        return true;
    }
    return (i < j);
  });

  for (unsigned int i = 0; i < answer.size(); i++) {
    if (answer[i].size() != results[i].size())
      return false;
    for (unsigned int j = 0; j < answer[i].size(); j++) {
      if (answer[i][j] != results[i][j])
        return false;
    }
  }

  return true;
}

void dump(vector<vector<int>> answer, vector<int> candidates) {
  cout << "Answer:" << endl;
  for (auto a : answer) {
    cout << "  ";
    for (unsigned int i = 0; i < a.size(); i++) {
      if (i > 0)
        cout << ", ";
      cout << a[i];
    }
    cout << endl;
  }

  cout << "Candidates:" << endl;
  cout << "  ";
  for (unsigned int i = 0; i < candidates.size(); i++) {
    if (i > 0)
      cout << ", ";
    cout << candidates[i];
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  int test_case = 1;

  while (1) {
    int target;
    vector<int> candidates;
    vector<vector<int>> answer;
    vector<vector<int>> results;
    Solution s;

    if (!(get_target(target)))
      break;
    if (!(get_candidates(candidates)))
      break;
    if (!(get_answer(answer)))
      break;

    // dump(answer, candidates);

    results = s.combinationSum(candidates, target);

    cout << "Test " << std::left << setw(3) << test_case++ << ": ";
    if (verify(results, answer)) {
      cout << "[PASS]";
    } else {
      cout << "[FAIL]";
    }
    cout << endl;
  }

  return 0;
}
