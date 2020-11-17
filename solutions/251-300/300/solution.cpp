#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    vector<int> record;

    if (nums.size() > 0) {
      record.push_back(nums[0]);
    }
    for (int i = 1; i < nums.size(); i++) {
      int n = nums[i];
      if (n > record.back()) {
        record.push_back(n);
      } else {
        *lower_bound(record.begin(), record.end(), n) = n;
      }
    }

    return record.size();
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};

  cout << s.lengthOfLIS(nums) << endl;

  return 0;
}

#endif
