#ifdef LOCAL_TEST
#include "solution.h"
#else

class Solution {
public:
  int count(vector<int> &height, unsigned int begin, unsigned int end);
  int trap(vector<int> &height);
};

#endif

int Solution::count(vector<int> &height, unsigned int begin, unsigned int end) {
  int sum = 0, minimum = min(height[begin], height[end]);

  while (++begin < end) {
    sum = sum + minimum - height[begin];
  }

  return sum;
}

int Solution::trap(vector<int> &height) {
  int sum = 0;
  unsigned int begin, end;
  vector<unsigned int> indices;

  if (height.size() == 0)
    return 0;

  for (unsigned int i = 0; i < height.size(); i++) {
    indices.push_back(i);
  }

  sort(indices.begin(), indices.end(),
       [=](unsigned int a, unsigned int b) { return height[a] > height[b]; });

  /* Count the left side. */
  begin = 1;
  end = 0;
  while (begin < indices.size()) {
    if (indices[begin] < indices[end]) {
      sum += count(height, indices[begin], indices[end]);
      end = begin;
    }
    begin++;
  }

  /* Count the right side. */
  begin = 0;
  end = 1;
  while (end < indices.size()) {
    if (indices[begin] < indices[end]) {
      sum += count(height, indices[begin], indices[end]);
      begin = end;
    }
    end++;
  }

  return sum;
}
