#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    map<int, int> table;
    vector<int> keys;

    for (auto n : nums) {
      table[n] += 1;
    }

    for (auto t : table) {
      keys.push_back(t.first);
    }

    sort(keys.begin(), keys.end(),
         [&](int a, int b) { return table[a] > table[b]; });

    return vector<int>(keys.begin(), keys.begin() + k);
  }
};

#ifdef LOCAL_TEST

void dump(vector<int> nums) {
  cout << "[";
  for (int i = 0; i < nums.size(); ++i) {
    if (i > 0)
      cout << ", ";
    cout << nums[i];
  }
  cout << "]";
}

int main(int argc, char *argv[]) {
  Solution s;
  vector<int> array;

  array.push_back(1);
  array.push_back(1);
  array.push_back(1);
  array.push_back(2);
  array.push_back(2);
  array.push_back(3);
  dump(s.topKFrequent(array, 2));
  cout << endl;

  array.clear();
  array.push_back(1);
  dump(s.topKFrequent(array, 1));
  cout << endl;

  return 0;
}

#endif
