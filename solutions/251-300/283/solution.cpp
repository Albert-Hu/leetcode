#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int current = 0, next = 1;
    while (current < nums.size() && next < nums.size()) {
      if (nums[current] == 0) {
        if (next <= current) {
          next = current + 1;
        }
        while (next < nums.size()) {
          if (nums[next] != 0) {
            swap(nums[current], nums[next]);
            break;
          }
          next++;
        }
      }
      current++;
    }
  }
};

#ifdef LOCAL_TEST
void dump(vector<int> &nums) {
  cout << "[";
  for (int i = 0; i < nums.size(); i++) {
    if (i > 0)
      cout << ", ";
    cout << nums[i];
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums;

  nums.clear();
  nums.push_back(0);
  nums.push_back(1);
  nums.push_back(0);
  nums.push_back(3);
  nums.push_back(12);
  s.moveZeroes(nums);
  dump(nums);

  return 0;
}

#endif
