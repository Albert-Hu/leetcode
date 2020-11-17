#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
  int search(int start, int end) {
    int count = 0;

    if (table.count(start << 8 | end) > 0) {
      return table[start << 8 | end];
    }

    if (start > end)
      return 0;

    if (start == end)
      return 1;

    for (int i = start; i <= end; i++) {
      int left = search(start, i - 1);
      int right = search(i + 1, end);
      if (left == 0 || right == 0)
        count = count + left + right;
      else
        count = count + left * right;
    }

    table[start << 8 | end] = count;

    return count;
  }

  int numTrees(int n) { return search(1, n); }

  map<int, int> table;
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;

  for (int i = 1; i <= 19; i++) {
    cout << i << ": " << s.numTrees(i) << endl;
  }

  return 0;
}

#endif
