#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    vector<int> nums;
    map<int, int> exists;

    for (auto n : nums1) {
      exists[n]++;
    }

    for (auto n : nums2) {
      if (exists[n] > 0) {
        nums.push_back(n);
        exists[n]--;
      }
    }

    return nums;
  }
};

#ifdef LOCAL_TEST
void dump(vector<int> nums) {
  cout << "[";
  for (int i = 0; i < nums.size(); i++) {
    if (i > 0) cout << ", ";
    cout << nums[i];
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums1;
  vector<int> nums2;

  nums1.clear();
  nums1.push_back(1);
  nums1.push_back(2);
  nums1.push_back(2);
  nums1.push_back(1);
  nums2.clear();
  nums2.push_back(2);
  nums2.push_back(2);
  dump(s.intersect(nums1, nums2));

  nums1.clear();
  nums1.push_back(4);
  nums1.push_back(9);
  nums1.push_back(5);
  nums2.clear();
  nums2.push_back(9);
  nums2.push_back(4);
  nums2.push_back(9);
  nums2.push_back(8);
  nums2.push_back(4);
  dump(s.intersect(nums1, nums2));

  nums1.clear();
  nums1.push_back(2);
  nums1.push_back(1);
  nums2.clear();
  nums2.push_back(1);
  nums2.push_back(1);
  dump(s.intersect(nums1, nums2));

  return 0;
}

#endif
