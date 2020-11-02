#include "sort.h"

void sort(vector<int> &array) {
  for (int length = array.size(); length > 0; length--) {
    for (int i = 1; i < length; i++) {
      if (array[i] < array[i - 1]) {
        swap(array[i], array[i - 1]);
      }
    }
  }
}
