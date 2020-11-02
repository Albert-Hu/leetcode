#include "sort.h"

void sort(vector<int> &array, int start, int end) {
  if (start < end) {
    int middle = array[start], s = start + 1, e = end;
    while (s < e) {
      while (s < e && array[s] < middle) s++;
      while (s < e && middle <= array[e]) e--;
      swap(array[s], array[e]);
    }
    if (array[start] > array[s])
      swap(array[start], array[s]);
    sort(array, start, e - 1);
    sort(array, s, end);
  }
}

void sort(vector<int> &array) {
  sort(array, 0, array.size() - 1);
}
