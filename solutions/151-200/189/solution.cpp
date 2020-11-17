#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
#if 1
  void rotate(vector<int> &nums, int k) {
    const int n = nums.size();

    k = k % n;
    for (int count = 0, start = 0; count < n; start++) {
      int current = start;
      int previous = nums[current];
      do {
        int next = (current + k) % n;
        int temp = nums[next];
        nums[next] = previous;
        previous = temp;
        current = next;
        count++;
      } while (start != current);
    }
  }
#else
  void rotate(vector<int> &nums, int k) {
    const int n = nums.size();
    vector<int> clone(nums.begin(), nums.end());

    k = k % n;
    for (int i = 0; i < n; i++) {
      nums[(k + i) % n] = clone[i];
    }
  }
#endif
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
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);
  nums.push_back(5);
  nums.push_back(6);
  nums.push_back(7);
  s.rotate(nums, 3);
  dump(nums);

  nums.clear();
  nums.push_back(-1);
  nums.push_back(-100);
  nums.push_back(3);
  nums.push_back(99);
  s.rotate(nums, 2);
  dump(nums);

  return 0;
}

#endif
