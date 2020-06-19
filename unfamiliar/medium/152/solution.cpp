#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    return 0;  
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums;

  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(-2);
  nums.push_back(4);
  cout << s.maxProduct(nums) << endl;

  nums.clear();
  nums.push_back(-2);
  nums.push_back(0);
  nums.push_back(-1);
  cout << s.maxProduct(nums) << endl;

  return 0;
}

#endif
