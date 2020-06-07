#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int l = 1, r = 1, n = nums.size();
    vector<int> answer(n, 1);
    for (int i = 0; i < n; i++) {
      int end = n - i - 1;
      answer[i] *= l;
      answer[end] *= r;
      l *= nums[i];
      r *= nums[end];
    }
    return answer;
  }
};

#ifdef LOCAL_TEST

void dump(vector<int> ans) {
  cout << "[";
  for (int i = 0; i < ans.size(); i++) {
    if (i > 0) cout << ", ";
    cout << ans[i];
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums;

  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(4);

  dump(s.productExceptSelf(nums));

  return 0;
}

#endif
