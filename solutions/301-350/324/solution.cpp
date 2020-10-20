#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  void wiggleSort(vector<int> &nums) {
    n_solution(nums);
  }

  /*
   * time complexity O(n)
   * space complexity O(1)
   */
  void n_solution(vector<int> &nums) {
    /*
     * index mapping as following:
     * original: 0 1 2 3 4 5 6 7 8 9
     * rewire:   1 3 5 7 9 0 2 4 6 8
     */
    #define REWIRE_INDEX(i, n) ((1 + ((i) * 2)) % ((n) | 1))
    int n = nums.size();
    auto middle_it = nums.begin() + (n / 2);

    nth_element(nums.begin(), middle_it, nums.end());
    int middle = *middle_it;

    // three way partition
    for (int i = 0, j = 0, k = n - 1; j <= k;) {
      if (nums[REWIRE_INDEX(j,n)] > middle) {
        swap(nums[REWIRE_INDEX(i++,n)], nums[REWIRE_INDEX(j++,n)]);
      } else if (nums[REWIRE_INDEX(j,n)] < middle) {
        swap(nums[REWIRE_INDEX(k--,n)], nums[REWIRE_INDEX(j,n)]);
      } else {
        j++;
      }
    }
  }

  /*
   * time complexity O(nlogn) + O(n)
   * space complexity O(n)
   */
  void nlogn_plus_n_solution(vector<int> &nums) {
    vector<int> clone(nums.begin(), nums.end());
    int n = nums.size();
    int a = (nums.size() + 1) / 2;
    int b = n;
    sort(clone.begin(), clone.end());

    for (int i = 0; i < n; i++) {
      nums[i] = ((i % 2) == 0) ? clone[--a] : clone[--b];
    }
  }
};

#ifdef LOCAL_TEST

void dump(vector<int> &nums) {
  cout << "[";
  for (int i = 0; i < nums.size(); i++) {
    if (i > 0) cout << ", ";
    cout << nums[i];
  }
  cout << "]" << endl;
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> nums;

  nums.push_back(1);
  nums.push_back(5);
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(6);
  nums.push_back(4);
  s.wiggleSort(nums);
  dump(nums);

  nums.clear();
  nums.push_back(1);
  nums.push_back(3);
  nums.push_back(2);
  nums.push_back(2);
  nums.push_back(3);
  nums.push_back(1);
  s.wiggleSort(nums);
  dump(nums);

  return 0;
}

#endif
