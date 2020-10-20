#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  bool canJump(vector<int>& nums) {
    vector<bool> visited(nums.size(), false);
    return search(nums, visited, 0);
  }
private:
  bool search(vector<int> &nums, vector<bool> &visited, int index) {
    const int n = nums.size() - 1;
    if (index >= n) {
      return true;
    }
    if ((index + nums[index]) >= n) {
      return true;
    }
    for (int step = (index + nums[index]); step > index; --step) {
      if (visited[step]) {
        break;
      }
      if (search(nums, visited, step)) {
        return true;
      }
      visited[step] = true;
    }
    return false;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums;

  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(4);
  cout << (s.canJump(nums) ? "true" : "false") << endl;

  nums.clear();
  nums.push_back(3);
  nums.push_back(2);
  nums.push_back(1);
  nums.push_back(0);
  nums.push_back(4);
  cout << (s.canJump(nums) ? "true" : "false") << endl;

  return 0;
}

#endif
