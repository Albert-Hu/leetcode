#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int>& height) {
    int max = 0;
    int l = 0, r = height.size() - 1;
    while (l < r) {
      int x = r - l;
      if (height[l] < height[r]) {
        x *= height[l];
        l++;
      } else {
        x *= height[r];
        r--;
      }
      if (x > max) {
        max = x;
      }
    }
    return max;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> height;

  height.push_back(1);
  height.push_back(8);
  height.push_back(6);
  height.push_back(2);
  height.push_back(5);
  height.push_back(4);
  height.push_back(8);
  height.push_back(3);
  height.push_back(7);
  cout << s.maxArea(height) << endl;

  return 0;
}

#endif
