#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    int current = nums1.size() - 1;
    int a = m - 1, b = n - 1;

    while (a > -1 && b > -1) {
      if (nums1[a] > nums2[b]) {
        nums1[current] = nums1[a];
        a--;
      } else {
        nums1[current] = nums2[b];
        b--;
      }
      current--;
    }

    while (a > -1) {
      nums1[current--] = nums1[a--];
    }

    while (b > -1) {
      nums1[current--] = nums2[b--];
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
  vector<int> nums1;
  vector<int> nums2;

  nums1.push_back(1);
  nums1.push_back(2);
  nums1.push_back(3);
  nums1.push_back(0);
  nums1.push_back(0);
  nums1.push_back(0);

  nums2.push_back(2);
  nums2.push_back(5);
  nums2.push_back(6);

  s.merge(nums1, 3, nums2, 3);
  dump(nums1);

  return 0;
}

#endif
