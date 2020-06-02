#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, less<int>> q;
    
    k = nums.size() - k + 1;
    for (auto n : nums) {
      q.push(n);
      if (q.size() > k) {
        q.pop();
      }
    }

    return q.top();
  }
};

#ifdef LOCAL_TEST

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> array;
  
  array.push_back(3);
  array.push_back(2);
  array.push_back(1);
  array.push_back(5);
  array.push_back(6);
  array.push_back(4);
  cout << s.findKthLargest(array, 2) << endl;

  array.clear();
  array.push_back(3);
  array.push_back(2);
  array.push_back(3);
  array.push_back(1);
  array.push_back(2);
  array.push_back(4);
  array.push_back(5);
  array.push_back(5);
  array.push_back(6);
  cout << s.findKthLargest(array, 4) << endl;

  return 0;
}

#endif
