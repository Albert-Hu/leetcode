#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> answer;
    for (int i = 0; i < nums.size() && answer.size() != 2; ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        if ((nums[i] + nums[j]) == target) {
          answer.push_back(i);
          answer.push_back(j);
          break;
        }
      }
    }
    return answer;
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  vector<int> test;
  vector<int> result;
  Solution s;

  test.push_back(2);
  test.push_back(7);
  test.push_back(11);
  test.push_back(15);

  result = s.twoSum(test, 9);

  cout << "[" << result[0] << ", " << result[1] << "]" << endl;

  return 0;
}

#endif
