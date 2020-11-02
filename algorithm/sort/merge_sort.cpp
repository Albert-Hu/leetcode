#include "sort.h"

void merge(vector<int>::iterator target, vector<int> &a, vector<int> &b) {
  int a_index = 0, b_index = 0;

  while (a_index < a.size() && b_index < b.size()) {
    if (a[a_index] < b[b_index]) {
      *target++ = a[a_index++];
    } else {
      *target++ = b[b_index++];
    }
  }

  while (a_index < a.size()) {
    *target++ = a[a_index++];
  }

  while (b_index < b.size()) {
    *target++ = b[b_index++];
  }
}

void sort(vector<int> &array) {
  if (array.size() > 1) {
    int size = array.size() / 2;
    vector<int> left(array.begin(), array.begin() + size);
    vector<int> right(array.begin() + size, array.end());
    sort(left);
    sort(right);
    merge(array.begin(), left, right);
  }
}
