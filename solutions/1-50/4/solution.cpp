#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double median(vector<int> &nums) {
    int len = nums.size();
    return static_cast<double>(nums[len / 2] + nums[(len - 1) / 2]) / 2.;
  }

  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = nums1.size(), n = nums2.size(), len = m + n;
    if (nums1.size() < nums2.size())
      return findMedianSortedArrays(nums2, nums1);
    if (nums2.size() == 0)
      return static_cast<double>(nums1[(m - 1) / 2] + nums1[m / 2]) / 2.;

    int s = 0, e = n + n;
    double l1, l2, r1, r2;

    m += m;
    n += n;
    do {
      int x2 = (s + e) / 2;
      int x1 = len - x2;

      l2 = (x2 > 0) ? nums2[(x2 - 1) / 2] : static_cast<double>(INT32_MIN);
      r2 = (x2 < n) ? nums2[x2 / 2] : static_cast<double>(INT32_MAX);
      l1 = (x1 > 0) ? nums1[(x1 - 1) / 2] : static_cast<double>(INT32_MIN);
      r1 = (x1 < m) ? nums1[x1 / 2] : static_cast<double>(INT32_MAX);

      if (l1 > r2) {
        s = x2 + 1;
      } else if (l2 > r1) {
        e = x2 - 1;
      }
    } while (l1 > r2 || l2 > r1);

    return (max(l1, l2) + min(r1, r2)) / 2.;
  }
};

#ifdef LOCAL_TEST
int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums1, nums2;

  cout << setprecision(1);
  cout << fixed;

  nums1.clear();
  nums1.push_back(1);
  nums1.push_back(3);
  nums2.clear();
  nums2.push_back(2);
  cout << s.findMedianSortedArrays(nums1, nums2) << endl;

  nums1.clear();
  nums1.push_back(1);
  nums1.push_back(2);
  nums2.clear();
  nums2.push_back(3);
  nums2.push_back(4);
  cout << s.findMedianSortedArrays(nums1, nums2) << endl;

  nums1.clear();
  nums1.push_back(0);
  nums1.push_back(0);
  nums2.clear();
  nums2.push_back(0);
  nums2.push_back(0);
  cout << s.findMedianSortedArrays(nums1, nums2) << endl;

  nums1.clear();
  nums2.clear();
  nums2.push_back(1);
  cout << s.findMedianSortedArrays(nums1, nums2) << endl;

  nums1.clear();
  nums1.push_back(2);
  nums2.clear();
  cout << s.findMedianSortedArrays(nums1, nums2) << endl;

  nums1.clear();
  nums1.push_back(1);
  nums2.clear();
  nums2.push_back(2);
  nums2.push_back(3);
  cout << s.findMedianSortedArrays(nums1, nums2) << endl;

  nums1.clear();
  nums1.push_back(100001);
  nums2.clear();
  nums2.push_back(100000);
  cout << s.findMedianSortedArrays(nums1, nums2) << endl;

  return 0;
}
#endif
