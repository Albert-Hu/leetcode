#include <iostream>

#include "sort.h"

void dump(vector<int> &array) {
  bool comma = false;

  cout << "[";
  for (auto n : array) {
    if (comma) cout << ", ";
    else comma = true;
    cout << n;
  }
  cout << "]" << endl;
}

bool isSorted(vector<int> &array) {
  for (int i = 1; i < array.size(); i++) {
    if (array[i] < array[i - 1])
      return false;
  }
  return true;
}

int main(int argc, char *argv[]) {
  int n;
  vector<int> array;

  while (cin >> n) {
    array.push_back(n);
  }

  sort(array);

  cout << argv[0] << " ... ";
  if (isSorted(array)) {
    cout << "[SUCCESS]";
  } else {
    cout << "[FAIL]";
  }
  cout << endl;

  return 0;
}
